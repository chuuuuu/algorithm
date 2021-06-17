def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    X, Y, S = input().split(' ')
    # X: CJ, Y: JC
    X, Y = int(X), int(Y)
    N = len(S)
    if X > 0 and Y > 0:
        # S:  [??J???C?]
        # SL: [??JJJJCC]
        SL = [0] * N
        for i in range(N):
            SL[i] = S[i]
            if i != 0 and SL[i] == '?':
                SL[i] = SL[i-1]

        # SR: [JJJCCCC?]
        SR = [0] * N
        for i in range(N-1, -1, -1):
            SR[i] = S[i]
            if i != N-1 and SR[i] == '?':
                SR[i] = SR[i+1]
        
        S_arr = []
        for i in range(N):
            if S[i] != '?':
                S_arr.append(S[i])
            else:
                if SL[i] == '?' and SR[i] == '?':
                    return 0
                elif SL[i] != '?':
                    S_arr.append(SL[i])
                else:
                    S_arr.append(SR[i])
        
        ret = 0
        c_prev = S_arr[0]
        for i in range(1, N):
            c = S_arr[i]
            if c != c_prev:
                if c_prev == 'C':
                    ret += X
                else:
                    ret += Y
                c_prev = c

        return ret

if __name__ == '__main__':
    main()