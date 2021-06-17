# 7 3 6 9 5 4 1 8 2
# 123 -> 312 -> 312
# 
# using binary search
from collections import deque
import sys

def main():
    T, N, Q = [int(s) for s in input().split(' ')]
    for i in range(T):
        solve(N)

def solve(N):
    q = deque()
    query = [1, 2, 3]
    m, idx_m, idx_x, idx_y = get_m(query)
    q.append(query[idx_x])
    q.append(query[idx_m])
    q.append(query[idx_y])

    for n in range(4, N+1):
        # all index between q_idx_i and q_idx_j (inclusive) are possible position to insert
        q_idx_i = 0
        q_idx_j = len(q)
        while True:
            # print(f'q: {q}, q_idx_i: {q_idx_i}, q_idx_j: {q_idx_j}', file=sys.stderr)
            # when there's only one possible position, then insert the number
            if q_idx_i == q_idx_j:
                q.insert(q_idx_i, n)
                break
            
            # when there're only two possible position, then query for the correct position, and insert the number
            if q_idx_i+1 == q_idx_j:
                if q_idx_j == len(q):
                    query[0] = q[len(q)-2]
                    query[1] = q[len(q)-1]
                    query[2] = n

                    m, idx_m, idx_x, idx_y = get_m(query)
                    if idx_m == 1:
                        q.insert(len(q), n)
                    elif idx_m == 2:
                        q.insert(len(q)-1, n)

                    break
                
                else:
                    query[0] = q[q_idx_i]
                    query[1] = q[q_idx_j]
                    query[2] = n

                    m, idx_m, idx_x, idx_y = get_m(query)
                    if idx_m == 0:
                        q.insert(q_idx_i, n)
                    elif idx_m == 2:
                        q.insert(q_idx_j, n)

                    break

            # binary search
            q_idx_m1 = (q_idx_j - q_idx_i) * 1 // 3 + q_idx_i
            q_idx_m2 = (q_idx_j - q_idx_i) * 2 // 3 + q_idx_i
            # print(f'm1: {q_idx_m1}, m2: {q_idx_m2}', file=sys.stderr)

            query[0] = q[q_idx_m1]
            query[1] = q[q_idx_m2]
            query[2] = n
            # print(f'query: {query}', file=sys.stderr)

            m, idx_m, idx_x, idx_y = get_m(query)
            # print(f'get_m: {query[idx_x]}, {query[idx_m]}, {query[idx_y]}', file=sys.stderr)
            
            if idx_m == 0:
                q_idx_j = q_idx_m1
            
            elif idx_m == 1:
                q_idx_i = q_idx_m2+1

            else:
                q_idx_i = q_idx_m1+1
                q_idx_j = q_idx_m2

    ans = ' '.join([str(n) for n in q])
    print(f'{ans}', flush=True)
    res = int(input())
    if res == -1:
        exit()
    
def get_m(query):
    x, y, z = query
    print(f'{x} {y} {z}', flush=True)
    m = int(input())
    if x == m:
        return m, 0, 1, 2

    if y == m:
        return m, 1, 0, 2

    if z == m:
        return m, 2, 0, 1

if __name__ == '__main__':
    main()