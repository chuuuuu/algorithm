#https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f

# (1 1 1)
# (1 (2 2))

# 4 ((66 ((8) 77)) 6 (((9)))))

# 4 66 8 77 6 9
# 4 ((66((8)77)6(((9

def main():
    t = int(input())
    for i in range(t):
        s = input()
        ans = solve(s)
        print(f"Case #{i+1}: {ans}")

def solve(s):
    s += '0'
    ret = ""
    n1 = 0
    for c in s:
        n2 = int(c)
        if n2 > n1:
            ret += (n2-n1) * '('
            ret += c
        elif n2 < n1:
            ret += (n1-n2) * ')'
            ret += c
        else:
            # n2 == n1
            ret += c
        n1 = n2

    return ret[:-1]

if __name__=="__main__":
   main()