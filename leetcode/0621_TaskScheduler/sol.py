# abcabca, n = 2
# abcabca, n = 3
# abc_abc_a, n = 4
# abacadaeaf, n = 2
# https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/

class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        myDict = {}
        for i in range(len(tasks)):
            if tasks[i] in myDict:
                myDict[tasks[i]] += 1
            else:
                myDict[tasks[i]] = 1
        
        maxCount = 0
        maxCountNum = 0
        for task, count in myDict.items():
            if count > maxCount:
                maxCount = count
                maxCountNum = 1
            elif count == maxCount:
                maxCountNum += 1
                
        print(maxCount, maxCountNum, len(tasks))
        return max((maxCount-1) * (n+1) + maxCountNum, len(tasks))