def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N, K = [int(s) for s in input().split(' ')]
    word = input()
    score = 0
    for i in range(N//2):
        if word[i] != word[len(word)-1 - i]:
            score += 1

    return abs(K - score)

if __name__ == '__main__':
    main()