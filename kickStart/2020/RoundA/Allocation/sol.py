def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N, B = [int(s) for s in input().split(' ')]
    As = [int(s) for s in input().split(' ')]
    
    As.sort()
    ans = 0
    cost = 0
    for A in As:
        cost += A
        if cost > B:
            break
        
        ans += 1

    return ans

if __name__ == '__main__':
    main()