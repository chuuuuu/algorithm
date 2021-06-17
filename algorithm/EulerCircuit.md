# Euler Circuit
We only consider undirected connected graph without self loop below. However, it can be easily to generalize for directed graph.

## Definition
- Euler Path
  - a path is Euler Path if
    - it goes through exactly once for every edges.

- Euler Circuit
  - a path is Euler Circuit if
    - it is an Euler Path.
    - it is also a cycle.

- Euler Walk
  - a random walk is an Euler Walk if
    - it doesnt pass an edge twice.

### Goal
- A path is an Euler Circuit if and only if the degree is even for every nodes.
- Find a Euler Circuit of the graph if it exists

### Lemma 1
If the graph has an Euler Circuit, then the degree is even for every nodes.

Let $P$ be a Euler Circuit.

- since $P$ is a path, it contains a start node $S$ and an end node $E$.
  - the node is a middle node if it is niether $S$ nor $E$.
- every time you visit a middle nodes, you'll go into the node, then go out the node.
  - since $P$ is a Euler Path, the degree of the middle. node is 2 * num_visited.
- since $P$ is a cycle, $S$ = $E$.
- since $P$ is a cycle, you can pick arbitrary node as $S$.
  - hence, $S$ is a middle node of some other Euler Circuit.
  - hence, the degree of $S$ is also even.

### Lemma 2
You can do an Euler Walk from every nodes and you'll visit the start node again if the degree is even for every node.

- remove the edge from the graph after you pass the edge.
  - hence degree of the two node of the edge will be decreased by one.
- you start from node $N_0$.
- after you arrive the next node $N_1$.
  - the degree of $N_0$ and $N_1$ will be odd.
- after you arrive the next node $N_2$.
  - the degree of $N_1$ will be even.
  - the degree of $N_2$ will be odd.
- if we dont visit $N_0$ after we cannot do Euler Walk anymore.
  - the nodes visited except $N_0$ are $\{N_1, N_2...\}$.
  - there exist $N_i$ such that its degree is odd.
    - hence, you did not finish the Euler Walk yet.
      - contradiction
      - we must visit $N_0$ before we cannot do Euler Walk.

### Hierholzer’s Algorithm
if the degree is even for every node, then we can use the algorithm below to find a Euler Circuit.
- let $L$ be a list
- pick an arbitrary node as start node $S$
- $DFS(S)$
- return $L$
<br>
- define $DFS(S)$
  - for every edge of $S$
    - let $E$ be the edge
    - let $N$ be the neighbor
    - remove $E$ from the graph
    - $DFS(N)$
    - append $E$ to $L$


### Lemma 3
The graph contains Euler circuit if the degree is even for every nodes.

- According to Hierholzer’s Algorithm, we can find a Euler Circuit if the degree is even for every nodes.