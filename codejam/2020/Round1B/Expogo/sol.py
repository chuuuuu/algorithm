# (2, 3) -> 2+3 = 5 = 101 = 4+1 = 4+(2-1) -> (2, 4-1)
# (2, 15) -> 2+15 = 17 = 10001 = 16+1 = 16+(8-4-2-1) -> (8-4-2, 16-1)
# (23, 24) -> 23+24 = 47 = 101111 = 32+(16-8)+4+2+1 -> (16+4+2+1, 32-8)
# (23, 14) -> 23+14 = 37 = 100101 = 32+(16-8-4)+(2-1) -> (32-8-1, 16-4+2)
# 14 = 1110 = 8+4+2 = 8+4+(4-4)+2 = 8+8-4+2 = 16-4+2
# 37 -> (1, 1, -1, -1, 1, -1)
# 14 -> (1, 1, 1, 0) -> (1+1, -1, 1, 0) -> (1, 0, -1, 1, 0)

def main():
    t = int(input())
    for i in range(t):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    x, y = [int(s) for s in input().split(' ')]
    if (x + y) % 2 == 0:
        return 'IMPOSSIBLE'

    x_isNeg, y_isNeg = False, False
    if x < 0:
        x_isNeg = True
        x = -x
    if y < 0:
        y_isNeg = True
        y = -y

    s = x + y
    s_bits = get_bits(s)

    for i in range(len(s_bits)-1):
        if s_bits[i+1] == 0:
            s_bits[i] = -1
        else:
            s_bits[i] = 1

    x_bits = get_bits(x)
    idx = 0
    while True:
        if idx == len(x_bits):
            break

        if x_bits[idx] == 0:
            idx += 1
            continue

        if x_bits[idx] == 2:
            if idx+1 == len(x_bits):
                x_bits.append(0)
            x_bits[idx] = 0
            x_bits[idx+1] += 1
            idx += 1
            continue

        if x_bits[idx] == 1:
            if s_bits[idx] == 1:
                idx += 1
                continue

            if s_bits[idx] == -1:
                if idx+1 == len(x_bits):
                    x_bits.append(0)
                x_bits[idx] = -1
                x_bits[idx+1] += 1
                idx += 1
                continue

    ans = [0] * len(s_bits)
    dirs = ['N', 'S', 'E', 'W']
    for i in range(len(s_bits)):
        dirIdx = 0
        if s_bits[i] == -1:
            dirIdx = 1
        if i < len(x_bits):
            if x_bits[i] != 0:
                dirIdx = dirIdx + 2
                if x_isNeg:
                    dirIdx = dirIdx ^ 1
        
            elif y_isNeg:
                dirIdx = dirIdx ^ 1

        elif y_isNeg:
                dirIdx = dirIdx ^ 1

        ans[i] = dirs[dirIdx]
    
    return ''.join(ans)

def get_bits(n):
    bits = []
    while n > 0:
        bit = n % 2
        bits.append(bit)
        n = n >> 1

    return bits

if __name__ == '__main__':
    main()