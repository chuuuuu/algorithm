# for python, if you want to modify a long string
# for example: s = s + '123'
# python would copy the string s
# the better way to process string is to make an array for it.


def main():
    t = int(input())
    for i in range(t):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    n = int(input())
    ps = [] # patterns
    for _ in range(n):
        ps.append(input())

    # there're at least one '*' in the string
    p1 = []    # *A*
    p2 = []    # A*A
    p3 = []    # *A
    p4 = []    # A*

    for p in ps:
        if '*' == p[0]:
            if '*' == p[-1]:
                p1.append(p)
            else:
                p3.append(p)
        else:
            if '*' == p[-1]:
                p4.append(p)
            else:
                p2.append(p)

    success = check(p2+p4, False) and check(p2+p3, True)
    if not success:
        return '*'

    # ret = ret1 + middle strings + ret2
    ret1 = ""
    maxStarPos = [None, -1] # maxStarPos: [string s with max star pos, the index]
    for p in p2+p4:
        idx = getStarPos(p, False)
        if idx > maxStarPos[1]:
            maxStarPos = [p, idx]

    if maxStarPos[0] != None:    
        ret1 = maxStarPos[0][:maxStarPos[1]]

    ret2 = ""
    maxStarPos = [None, 1] # maxStarPos: [string s with max star pos, the index]
    for p in p2+p3:
        idx = getStarPos(p, True)
        if idx < maxStarPos[1]:
            maxStarPos = [p, idx]
    
    if maxStarPos[0] != None:
        ret2 = maxStarPos[0][maxStarPos[1]:][1:]
    
    ret = ret1
    for p in p1:
        ss = p.split('*')    
        ret += ''.join(ss[:])

    for p in p2:
        ss = p.split('*')    
        ret += ''.join(ss[1:-1])

    for p in p3:
        ss = p.split('*')
        ret += ''.join(ss[:-1])

    for p in p4:
        ss = p.split('*')    
        ret += ''.join(ss[1:])

    ret += ret2

    return ret

def getStarPos(p, reverse):
    start_idx = 0
    unit = 1
    if reverse:
        start_idx = -1
        unit = -1

    pos = start_idx
    while True:
        if p[pos] == '*':
            return pos
        
        pos += unit

# check if ps are consistance
def check(ps, reverse):
    start_idx = 0 # start from 0
    unit = 1 # record direction
    if reverse:
        start_idx = -1
        unit = -1

    pls = [] # pattern length
    l = start_idx
    l_max = 0
    for p in ps:
        while p[l] != '*':
            l += unit
        pls.append(abs(l-start_idx))
        l_max = max(l_max, abs(l-start_idx))
        l = start_idx

    s = []
    for i in range(l_max):
        s.append(None)
    
    for i in range(len(ps)):
        for j in range(abs(pls[i])):
            idx = start_idx + j * unit
            c = ps[i][idx]
            if s[j] is None:
                s[j] = c
            elif c != s[j]:
                return False

    return True




if __name__ == "__main__":
    main()