def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N = int(input())
    L = [int(s) for s in input().split(' ')]

    ret = 0
    for i in range(N-1):
        j = find(L, i)
        ret += j+1-i
        middle = L[i:j+1]
        middle.reverse()
        L = L[:i] + middle + L[j+1:]

    return ret

def find(L, i):
    N = len(L)
    min_num = float('inf')
    min_idx = -1
    for j in range(i, N, 1):
        if L[j] < min_num:
            min_num = L[j]
            min_idx = j

    return min_idx

if __name__ == '__main__':
    main()