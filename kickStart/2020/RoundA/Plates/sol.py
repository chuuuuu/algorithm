def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    # N stacks, K plates for each, P plates
    N, K, P = [int(s) for s in input().split(' ')]
    Bs = []
    for i in range(N):
        Bs.append([int(s) for s in input().split(' ')])
    
    BSs = [[0 for i in range(K+1)] for j in range(N+1)]
    for i in range(1, N+1):
        for j in range(1, K+1):
            BSs[i][j] = BSs[i][j-1] + Bs[i-1][j-1]
    
    # dp[i][j]: max beauty with i plates and j stacks
    dp = [[0 for i in range(N+1)] for j in range(P+1)]
    for i in range(1, P+1):
        for j in range(1, N+1):
            maxB = 0
            for k in range(min(i, K)+1):
                maxB = max(dp[i-k][j-1]+BSs[j][k], maxB)
            dp[i][j] = maxB

    return dp[-1][-1]

if __name__ == '__main__':
    main()