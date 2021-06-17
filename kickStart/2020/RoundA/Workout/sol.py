def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N, K = [int(s) for s in input().split(' ')]
    Ms = [int(s) for s in input().split(' ')]
    Ds = [0] * (N-1)
    D_max = float('-inf')
    D_min = 1

    for i in range(N-1):
        Ds[i] = Ms[i+1] - Ms[i]
        D_max = max(D_max, Ds[i])
    
    D_divider = (D_max + D_min) // 2
    while True:
        if D_min+1 >= D_max:
            addition_num = get_addition_num(Ds, D_min)
            if addition_num <= K:
                return D_min
            
            return D_max

        addition_num = get_addition_num(Ds, D_divider)

        if addition_num > K:
            D_min = D_divider
            D_divider = (D_max + D_min) // 2
            continue

        if addition_num == K:
            D_max = D_divider
            D_divider = (D_max + D_min) // 2
            continue

        if addition_num < K:
            D_max = D_divider
            D_divider = (D_max + D_min) // 2

    return ans

def get_addition_num(Ds, D_divider):
    addition_num = 0
    for D in Ds:
        if D > D_divider:
            count = D // D_divider - 1
            if D > (count+1) * D_divider:
                count += 1
            addition_num += count

    return addition_num

if __name__ == '__main__':
    main()