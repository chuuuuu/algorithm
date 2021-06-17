# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c#problem

def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        matrix = getMatrix(n)
        trace, r, c = solve(matrix)
        print(f"Case #{i+1}: {trace} {r} {c}")

def getMatrix(n):
    matrix = []
    for _ in range(n):
        arr = [int(c) for c in input().split(' ')]
        matrix.append(arr)

    return matrix

def solve(matrix):
    # r = # of rows with repeated
    # c = # of columns with repeated
    trace = 0 
    n = len(matrix)
    for i in range(n):
        trace += matrix[i][i]

    r =  0
    for i in range(n):
        arr = matrix[i]
        counter = {}
        for j in range(n):
            emt = arr[j]
            if emt not in counter:
                counter[emt] = True
            else:
                r += 1
                break

    c =  0
    for i in range(n):
        arr = getCol(matrix, i)
        counter = {}
        for j in range(n):
            emt = arr[j]
            if emt not in counter:
                counter[emt] = True
            else:
                c += 1
                break

    return trace, r, c

def getCol(matrix, idx):
    n = len(matrix)
    col = []
    for i in range(n):
        col.append(matrix[i][idx])

    return col

if __name__=="__main__":
   main()