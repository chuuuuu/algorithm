class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        if len(chars) == 0:
            return []
        
        char = ""
        count = 0
        ret = []
        for i in range(len(chars)):
            if char != chars[i]:
                if char != "":
                    ret.append(char)
                    if count > 1:
                        for c in str(count):
                            ret.append(c)
                
                char = chars[i]
                count = 1
            else:
                count += 1
        
        ret.append(char)
        if count > 1:
            for c in str(count):
                ret.append(c)
            
        while len(chars) != 0:
            chars.pop()
            
        for i in range(len(ret)):
            chars.append(ret[i])
            
        return len(chars)

