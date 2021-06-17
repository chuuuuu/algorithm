# after every #10n+1 query
# 1. reverse
# 2. complement
# 3. reverse + complement
# 4. nothing

# at most 150 queries
# B_length_max = 100

# bits[0]
# 1...0 / 0...1 -> changed: 1 or 2, unchanged: 3 or 4

# bits[1]
# 1...1 / 0...0 -> changed: 2 or 3, unchanged: 1 or 4

# choose a couple of bits for each kind
# e.g. 11...10 or 10...00 or 01...11 or 00...01
import sys

def main():
    t, n = [int(c) for c in input().split(' ')]
    for _ in range(t):
        solve(n)

def solve(n):
    # print(f"{n}", file=sys.stderr)
    visitedMap = {}
    bit_pos_arrs = [[], []]
    pos_prev = 0
    for _ in range(15):            
        # print(f"{bit_pos_arrs}", file=sys.stderr)
        if len(bit_pos_arrs[0]) == 0 and len(bit_pos_arrs[1]) == 0:
            # append two new bit
            pos = pos_prev + 1
            pos1, pos2 = pos, n+1-pos
            if pos1 not in visitedMap:
                visitedMap[pos1] = True
                visitedMap[pos2] = True
                bit1, bit2 = getTwoBits(pos1, pos2)
                if bit1 == bit2:
                    bit_pos_arrs[1].append([bit1, pos1])
                    bit_pos_arrs[1].append([bit2, pos2])
                else:
                    bit_pos_arrs[0].append([bit1, pos1])
                    bit_pos_arrs[0].append([bit2, pos2])
            
            else:
                bit1, bit2 = getTwoBits(pos1, pos2)

            pos_prev = pos % n

        elif len(bit_pos_arrs[1]) != 0 and len(bit_pos_arrs[0]) == 0:
            bit, pos = bit_pos_arrs[1][0]
            bit_new, _ = getTwoBits(pos, pos)
            if bit_new != bit:
                complement(bit_pos_arrs[1])

        elif len(bit_pos_arrs[0]) != 0 and len(bit_pos_arrs[1]) == 0:
            bit, pos = bit_pos_arrs[0][0]
            bit_new, _ = getTwoBits(pos, pos)
            if bit_new != bit:
                complement(bit_pos_arrs[0])

        else:
            # either bit_pos_arrs[0] nor bit_pos_arrs[1] are empty
            bit0, pos0 = bit_pos_arrs[0][0]
            bit1, pos1 = bit_pos_arrs[1][0]
            bit0_new, bit1_new = getTwoBits(pos0, pos1)
            if bit0 == bit0_new:
                if bit1 == bit1_new:
                    pass
                    
                elif bit1 != bit1_new:
                    # reverse(bit_pos_arrs[0], n)
                    # reverse(bit_pos_arrs[1], n)
                    # complement(bit_pos_arrs[0])
                    complement(bit_pos_arrs[1])

            elif bit0 != bit0_new:
                if bit1 == bit1_new:
                    reverse(bit_pos_arrs[0], n)
                    # reverse(bit_pos_arrs[1], n)

                elif bit1 != bit1_new:
                    complement(bit_pos_arrs[0])
                    complement(bit_pos_arrs[1])

        for _ in range(4):
            # append two new bit
            pos = pos_prev + 1
            pos1, pos2 = pos, n+1-pos
            if pos1 not in visitedMap:
                visitedMap[pos1] = True
                visitedMap[pos2] = True
                bit1, bit2 = getTwoBits(pos1, pos2)
                if bit1 == bit2:
                    bit_pos_arrs[1].append([bit1, pos1])
                    bit_pos_arrs[1].append([bit2, pos2])
                else:
                    bit_pos_arrs[0].append([bit1, pos1])
                    bit_pos_arrs[0].append([bit2, pos2])
            
            else:
                bit1, bit2 = getTwoBits(pos1, pos2)
            
            pos_prev = pos % n


    bits = []
    for _ in range(n):
        bits.append(0)

    for bit_pos in bit_pos_arrs[0]:
        bit, pos = bit_pos
        bits[pos-1] = bit

    for bit_pos in bit_pos_arrs[1]:
        bit, pos = bit_pos
        bits[pos-1] = bit
    
    ans = ""
    for bit in bits:
        ans += bit
    
    print(ans, flush=True)
    if(input() != 'Y'):
        exit(-1)

def getTwoBits(pos1, pos2):
    ret = []
    print(pos1, flush=True)
    ret.append(input())
    print(pos2, flush=True)
    ret.append(input())

    return ret

def complement(bit_pos_arr):
    for bit_pos in bit_pos_arr:
        bit, _ = bit_pos
        if bit == '0':
            bit_pos[0] = '1'
        else:
            # bit == '1'
            bit_pos[0] = '0'

def reverse(bit_pos_arr, n):
    for bit_pos in bit_pos_arr:
        _, pos = bit_pos
        bit_pos[1] = n+1-pos

if __name__=="__main__":
   main()