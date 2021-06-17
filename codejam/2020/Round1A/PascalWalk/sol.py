# ref: https://www.youtube.com/watch?v=OlpC2d1Odrs

# N = 44 = 101100 -> walk through rows [2, 3, 5]
# however 2^2 + 2^3 + 2^5 + 6(the biggest row number + 1) - 3(num of rows) > 44, if i walk through those rows
# and the only operation i can do is addition
# hence, the strategy is that i should make a smaller number (but close to the target) and get to the target by adding with 1s
# it's important to notice that the biggest target would be 10^9, which is smaller than 2^30
# hence, the biggest row is row-29th. (the first row is row-0th)
# and the total number of the nodes above row-29th is (1+30)*30/2 = 465 which is less than the require number(500)
# since we have to add up the biggest row number + 1 on the left hand side.
# we can 30 to the target first (since the number added wont be greater than 30)

# Now, we can look at the example again.
# N = 44 => N' = 14 = 1110 => walk throuhg rows [1, 2, 3]
# 2^1 + 2^2 + 2^3 + 4 - 3 = 15 => we need to walk 1s for 44 - 15 times.

def main():
    t = int(input())
    for i in range(t):
        anss = solve()
        print(f'Case #{i+1}:')
        for ans in anss:
            print(f'{ans[0]} {ans[1]}')

def solve():
    n = int(input())
    if n <= 30:
        ret =  []
        for i in range(n):
            ret.append((i+1, 0+1))

        return ret

    n_prime = n - 30
    bits = [0] * 30
    max_row = 0
    bit_num = 0
    for i in range(30):
        if n_prime != 0:
            max_row += 1
        else:
            break

        bit = n_prime & 1
        if bit == 1:
            bit_num += 1

        bits[i] = bit
        n_prime = n_prime >> 1

    n_prime = n - 30        
    s_rows = n_prime + max_row - bit_num
    move_num = n - s_rows
    ret = []
    direction = "left"
    for i in range(max_row):
        if bits[i] == 0:
            if direction == "left":
                ret.append((i+1, 0+1))
            else:
                ret.append((i+1, i+1))
        else:
            if direction == "left":
                for j in range(i):
                    ret.append((i+1, j+1))
                
                ret.append((i+1, i+1))
                direction = "right"
            
            else:
                for j in range(i):
                    ret.append((i+1, i-j+1))
                
                ret.append((i+1, 0+1))
                direction = "left"

    for i in range(move_num):
        if direction == "left":
            ret.append((max_row+i+1, 0+1))
        
        else:
            ret.append((max_row+i+1, max_row+i+1))

    return ret


if __name__ == "__main__":
    main()