class Node:
    def __init__(self, c):
        self.c = c
        self.isEnd = False
        self.nodes = [None] * 26
        
    def connect(self, c):
        idx = ord(c) - ord('a')
        if not self.nodes[idx]:
            self.nodes[idx] = Node(c)
            
    def setIsEnd(self):
        self.isEnd = True
        
    def getNode(self, c):
        idx = ord(c) - ord('a')
        return self.nodes[idx]

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node('');

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        n = self.root
        for c in word:
            n.connect(c)
            n = n.getNode(c)
            
        n.setIsEnd()        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        n = self.root
        for c in word:
            n = n.getNode(c)
            if not n:
                return False
        
        if not n.isEnd:
            return False
        
        return True

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        n = self.root
        for c in prefix:
            n = n.getNode(c)
            if not n:
                return False
        
        return True        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)