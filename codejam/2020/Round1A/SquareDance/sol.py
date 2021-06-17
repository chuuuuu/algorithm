def main():
    t = int(input())
    for i in range(t):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    r, c = [int(s) for s in input().split(' ')]
    skills = []
    for i in range(r):
        skills.append([int(s) for s in input().split(' ')])

    skills_sum = sum([sum(row) for row in skills])

    nb = [] # nb[i][j] = [pos1, pos2, pos3, pos4] which represent the neighbor of (i, j)
    for i in range(r):
        nb.append([])
        for j in range(c):
            nb[i].append([])
            poss = [(i+1, j), (i-1, j), (i, j-1), (i, j+1)] # up, down, left, right
            for pos in poss:
                if pos[0] < r and pos[0] >= 0 and pos[1] < c and pos[1] >= 0:
                    nb[i][j].append(pos)
                else:
                    nb[i][j].append(None)

    get_nb_poss = lambda pos: nb[pos[0]][pos[1]]
    get_nb_skill_sum = lambda pos: sum([get_skill(nb_pos) for nb_pos in get_nb_poss(pos)])
    get_nb_num = lambda pos: sum([1 if nb_pos != None else 0 for nb_pos in get_nb_poss(pos)])
    get_skill = lambda pos: skills[pos[0]][pos[1]] if pos != None else 0

    interest = 0
    next_round_candidates = {}
    for i in range(r):
        for j in range(c):
            next_round_candidates[(i, j)] = True

    while len(next_round_candidates) != 0:
        interest += skills_sum
        current_round_candidates = next_round_candidates
        next_round_candidates = {}
        losers = {}
        for pos in current_round_candidates.keys():
            if get_nb_skill_sum(pos) > get_skill(pos) * get_nb_num(pos):
                losers[pos] = True

        for pos in losers.keys():
            skills_sum -= get_skill(pos)
            nb_poss = get_nb_poss(pos)
            for i in range(4):
                if nb_poss[i] != None:
                    get_nb_poss(nb_poss[i])[i^1] = nb_poss[i^1]
                    if nb_poss[i] not in losers:
                        next_round_candidates[nb_poss[i]] = True

    return interest

if __name__ == "__main__":
    main()