def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N = int(input())
    A = []
    for i in range(N):
        A.append([int(s) for s in input().split(' ')])
    B = []
    for i in range(N):
        B.append([int(s) for s in input().split(' ')])
    R = [int(s) for s in input().split(' ')]
    C = [int(s) for s in input().split(' ')]

    err_num_row = [0]*N
    err_num_col = [0]*N
    
    for i in range(N):
        for j in range(N):
            if A[i][j] == -1:
                err_num_row[i] += 1
                err_num_col[j] += 1
    


if __name__ == '__main__':
    solve()