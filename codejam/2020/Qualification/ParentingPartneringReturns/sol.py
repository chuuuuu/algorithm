def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        intervals = []
        for _ in range(n):
            interval = [int(c) for c in input().split(' ')]
            intervals.append(interval)

        ans = solve(n, intervals)
        print(f"Case #{i+1}: {ans}")

def solve(n, intervals):
    imp = "IMPOSSIBLE"
    for i in range(n):
        intervals[i].append(i)

    intervals.sort(key = lambda interval: interval[0])
    interval_prev = [-1, -1]
    couples = ['C', 'J']
    availableTime = [-1, -1]
    prev = 0
    for interval in intervals:
        if interval[0] < interval_prev[1]:
            current = prev ^ 1
            if availableTime[current] <= interval[0]:
                availableTime[current] = interval[1]
                interval.append(couples[current])
                prev = current
            else:
                return imp
        else:
            current = prev
            availableTime[current] = interval[1]
            interval.append(couples[prev])

        interval_prev = interval

    intervals.sort(key = lambda interval: interval[2])     
    ret = ""   
    for interval in intervals:
        ret += interval[3]

    return ret

if __name__=="__main__":
   main()