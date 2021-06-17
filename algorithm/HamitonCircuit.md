# Hamiton Path
it is an NP-complete problem.

## Ore's theorem
- suppose $G$ is a simple graph and $|V| \geq 3$
- if for any distinct node $x, y$, $deg(x)+deg(y) \geq n$
- then $G$ must contain Hamilton Cycle

## Properties
- http://tmtacm.blogspot.com/2016/01/hamilton-path.html
  - there exists a hamilton path in tournament graph
- there are lots of hamilton path in a complete graph

## Algorithm
it can be solved by dynamics programming with time complexity $O(n^2 \times 2^n)$

- s: state
  - e.g. for n=5
    - 11001 means a path contains 0, 1, 4 without repeat
- dp[i][s]: if there exists a state such that end node is i
  - e.g. for n=5
  - dp[1][11001] means if there exists a path contain 0, 1, 4 without repeat and the end node is 1
    - in this case, 0->4->1 or 4->0->1
  - there are $n\times2^n$ states
- we can use dynamic programming to find dp[i][s]
  - e.g. for n=5
  - dp[1][11001] = dp[0][10001] or dp[4][10001]
  - it cost n for every finding