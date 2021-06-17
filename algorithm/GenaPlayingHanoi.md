# Gena Playing Hanoi
Gena has a modified version of the Tower of Hanoi. His Hanoi has  rods and  discs ordered by ascending size. He made a few moves (following the rules above), but stopped and lost his place. He wants to restore the tower to its original state by making valid moves. Given the state of Gena's Hanoi, help him calculate the minimum number of moves needed to restore the tower to its original state.

nb: there're at most 10 dics

# analysis
since there would only be 4^10 states for 10 dics in this problem. we can build the graph of states(what is hanoi looks like now). and find the shortest path from starting state to ending state.