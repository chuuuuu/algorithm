# 4 6 
# 6 = 3 + 1 + 2
# 4 2 1 3
# 6 = 4 + 1 + 1
# 1 2 3 4
# 4 3 2 1

# 4 5
# 5 = 2 + 2 + 1
# 1 2 3 4
# 1 2 3 4
# 1 3 2 4
# 3 1 2 4

# 4 9
# 9 = 4 + 3 + 2
# 1 2 3 4
# 1 2 4 3
# 1 3 4 2
# 2 4 3 1

def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N, C = [int(s) for s in input().split(' ')]
    
    costs = [1] * (N-1)
    C -= N-1
    if C < 0:
        return 'IMPOSSIBLE'

    for i in range(N-1):
        cost = N-1 - i
        if C > cost:
            costs[i] += cost
            C -= cost
        else:
            costs[i] += C
            C = 0
    
    if C > 0:
        return 'IMPOSSIBLE'

    arr = []
    for i in range(N):
        arr.append(i+1)

    for i in range(N-2, -1, -1):
        cost = costs[i]
        middle = arr[i:i+cost]
        middle.reverse()
        arr = arr[:i] + middle + arr[i+cost:]

    return ' '.join([str(n) for n in arr])

if __name__ == '__main__':
    main()