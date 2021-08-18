def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    R, C = [int(s) for s in input().split(' ')]
    cells = []
    for i in range(R):
        cells.append([int(s) for s in input().split(' ')])

    top = []
    bottom = []
    left = []
    right = []
    for i in range(R):
        top.append([])
        bottom.append([])
        left.append([])
        right.append([])
        for j in range(C):
            top[i].append(0)
            bottom[i].append(0)
            left[i].append(0)
            right[i].append(0)

    for i in range(R):
        for j in range(C):
            num = cells[i][j]
            if num != 0 and i != 0:
                num += top[i-1][j]

            top[i][j] = num
    
    for i in range(R-1, -1, -1):
        for j in range(C):
            num = cells[i][j]
            if num != 0 and i != R-1:
                num += bottom[i+1][j]
            
            bottom[i][j] = num

    for i in range(R):
        for j in range(C):
            num = cells[i][j]
            if num != 0 and j != 0:
                num += left[i][j-1]
            left[i][j] = num

    for i in range(R):
        for j in range(C-1, -1, -1):
            num = cells[i][j]
            if num != 0 and j != C-1:
                num += right[i][j+1]
            right[i][j] = num

    ret = 0
    # for every (i, j) as the center of the L, and calculate all the possible combination
    for i in range(R):
        for j in range(C):
            # let right side of the center as the short side of L
            if right[i][j] >= 2:
                l = right[i][j]
                if top[i][j] >= 4:
                    if top[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += top[i][j] // 2 - 1

                if bottom[i][j] >= 4:
                    if bottom[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += bottom[i][j] // 2 - 1

            # let left side of the center as the short side of L
            if left[i][j] >= 2:
                l = left[i][j]
                if top[i][j] >= 4:
                    if top[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += top[i][j] // 2 - 1

                if bottom[i][j] >= 4:
                    if bottom[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += bottom[i][j] // 2 - 1

            # let top side of the center as the short side of L
            if top[i][j] >= 2:
                l = top[i][j]
                if right[i][j] >= 4:
                    if right[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += right[i][j] // 2 - 1

                if left[i][j] >= 4:
                    if left[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += left[i][j] // 2 - 1

            # let bottom side of the center as the short side of L
            if bottom[i][j] >= 2:
                l = bottom[i][j]
                if right[i][j] >= 4:
                    if right[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += right[i][j] // 2 - 1

                if left[i][j] >= 4:
                    if left[i][j] >= 2*l:
                        ret += l - 1
                    else:
                        ret += left[i][j] // 2 - 1
    
    return ret

if __name__ == '__main__':
    main()