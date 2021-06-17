import collections

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        nodes = []
        beginNode = Node(beginWord)
        nodes.append(beginNode)
        for word in wordList:
            nodes.append(Node(word))
            
        groups = {}
        for node in nodes:
            for edge in node.edges:
                if edge not in groups:
                    groups[edge] = []

                groups[edge].append(node)
        
        queue = collections.deque()
        queue.append(beginNode)
        beginNode.isVisited = True
        beginNode.level = 1
        
        while len(queue) != 0:
            current_node = queue.popleft()

            for edge in current_node.edges:
                for node in groups[edge]:
                    if node.isVisited:
                        continue
                    queue.append(node)
                    node.isVisited = True
                    node.level = current_node.level+1
                    if node.s == endWord:
                        return node.level
                        
        return 0
        
class Node(object):
    def __init__(self, s):
        self.s = s
        self.neighbors = []
        self.edges = []
        self.level = 0
        self.isVisited = False
        for i in range(len(s)):
            self.edges.append(s[:i] + '?' + s[i+1:])
                