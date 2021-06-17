import math
# import time

def main():
    # start_time = time.time()
    T = int(input())
    P = int(input())
    acc_to_skill = get_acc_to_skill()
    # end_time = time.time()
    # print(f'spend {end_time - start_time} sec')
    # start_time = time.time()
    for i in range(T):
        ans = solve(acc_to_skill)
        print(f'Case #{i+1}: {ans}')
        # end_time = time.time()
        # print(f'spend {end_time - start_time} sec')
        # start_time = time.time()


def solve(acc_to_skill):
    N_players = 100
    N_problems = 10000
    ans = []
    for i in range(N_players):
        ans.append(input())

    accs = [0] * N_players
    for i in range(N_players):
        for j in range(N_problems):
            accs[i] += int(ans[i][j]) / N_problems

    skills = [0] * N_players
    acc_to_skill_keys = list(acc_to_skill.keys())
    for i in range(N_players):
        acc = find_closest(acc_to_skill_keys, accs[i])
        skills[i] = acc_to_skill[acc]
    # print(skills)

    accs = [0] * N_problems
    for i in range(N_problems):
        for j in range(N_players):
            accs[i] += int(ans[j][i]) / N_players
    
    diffs = [0] * N_problems
    acc_to_diff = get_acc_to_diff(skills)
    acc_to_diff_keys = list(acc_to_diff.keys())
    for i in range(N_problems):
        acc = find_closest(acc_to_diff_keys, accs[i])
        diffs[i] = acc_to_diff[acc]
    # print(diffs)
    # print(sum(diffs))

    max_var = 0
    cheat_idx = 0
    for i in range(N_players):
        real_acc = 0
        expect_acc = 0

        for j in range(N_problems):
            skill = skills[i]
            diff = diffs[j]
            if diff > 2:
                acc = sigmoid(skill-diff)
                expect_acc += acc
                real_acc += int(ans[i][j])
        var = real_acc - expect_acc
        # print(i, var)
        if var > max_var:
            max_var = var
            cheat_idx = i

    return cheat_idx+1

def find_closest(arr, x):
    diff = float('inf')
    ret = 0
    for emt in arr:
        if abs(emt-x) < diff:
            diff = abs(emt-x)
            ret = emt
    
    return ret

def get_acc_to_skill():
    N_players = 1000
    N_problems = 1000
    skills = []
    for i in range(N_players):
        skill = -3 + 6/N_players * i
        skills.append(skill)

    diffs = []
    for i in range(N_problems):
        diff = -3 + 6/N_problems * i
        diffs.append(diff)

    acc_to_skill = {}
    for skill in skills:
        acc = 0
        for diff in diffs:
            acc += sigmoid(skill-diff) / (N_problems)
        
        acc_to_skill[acc] = skill

    return acc_to_skill


def get_acc_to_diff(skills):
    N_players = len(skills)
    N_problems = 100
    diffs = []
    for i in range(N_problems):
        diff = -3 + 6/N_problems * i
        diffs.append(diff)

    acc_to_diff = {}
    for diff in diffs:
        acc = 0
        for skill in skills:
            acc += sigmoid(skill-diff) / (N_players)
        
        acc_to_diff[acc] = diff

    return acc_to_diff

def sigmoid(x):
    return 1 / (1 + math.exp(-x)) 

if __name__ == '__main__':
    main()