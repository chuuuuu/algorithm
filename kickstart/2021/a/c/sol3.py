from collections import deque

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

    ret = 0
    nodes = []
    for i in range(R):
        for j in range(C):
            node = [i, j, cells[i][j]]
            nodes.append(node)
    
    nodes.sort(key=lambda node: node[2])
    nodes.reverse()
    ret = 0
    for node in nodes:
        ret += set_safe(node, cells)

    return ret

def set_safe(node, cells):
    R = len(cells)
    C = len(cells[0])
    x_start, y_start, h_start = node

    ds = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    cells_q = deque()
    cells_q.append([x_start, y_start])
    ret = 0    
    while len(cells_q) != 0:
        x, y = cells_q.popleft()
        h = cells[x][y]
        for d in ds:
            dx, dy = d
            x_new, y_new = x+dx, y+dy
            if x_new < 0 or x_new >= R or y_new < 0 or y_new >= C:
                continue

            if cells[x_new][y_new]+1 < h:
                ret += h-1 - cells[x_new][y_new]
                cells[x_new][y_new] = h-1
                cells_q.append([x_new, y_new])
    
    return ret

if __name__ == '__main__':
    main()