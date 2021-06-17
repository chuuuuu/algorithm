class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        myMap = {}
        for c in s:
            if c in myMap:
                myMap[c] += 1
            else:
                myMap[c] = 1
        
        items = list(myMap.items())
        items.sort(key = lambda x: -x[1])
        
        ret = ""
        for item in items:
            c, count = item
            ret += c * count
            
        return ret