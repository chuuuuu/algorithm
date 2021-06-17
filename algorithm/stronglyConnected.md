# Purpose
- find the strongly connected component in the graph
- can help us simplify the directed graph int DAG

## Kosaraju
### motivatioin
it's easy to find the strongly connected component in the undirected graph. 
 - we just need to traversal the graph with dfs
 - nodes are with the same starting point iff they are in the same connected compnent.

however, in directed graph, we may encounter the problem that we can walk from connected compnent A to connected compnent B, but we cannot conversely.

in this algorithm, it help us to decide the order of traversal with dfs. and we can get the strongly connected component just like an undirected graph

### algorithm

- reverse the graph
- traversal the graph with dfs
- mark the leaving order
- traversal with the leaving order