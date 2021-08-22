# Tarjan's Algorithm

## Terminology

### Spanning Tree

A tree, `T`, is a spanning tree of a graph, `G`, if

1. `T` is subgraph of `G`
2. `T` contains every vertex of `G`
3. `T` is a tree

### DFS Spanning Tree

After we do a DFS on a graph, it will give us a spanning tree.

### Preorder Number & Postorder number

We can store the preoder number & postorder number for each nodes.

### Ancestor and Descendant

`Node A` is the `ancestor` of `Node B` is equivalent to

1. `Node B` is the `descendant` of `Node A`
2. `Node A` is visiting if `Node B` is visiting

Note that `Node X` is both `ancestor` and `descendant` of `Node X`

### Types of Edge

There 4 types of edges in DFS spanning tree

1. `tree edge`:
   - part of DFS spanning tree
2. `forward edge`:
   - not tree edge
   - from ancestor to descendant
3. `backward edge`:
   - not tree edge
   - from descendant to ancestor
4. `cross edge`:
   - otherwise

### Types of Edges in Undirected Graph

1. There's no cross edge in undirected graph.
   - You can prove it with proof by contradiction.
2. backward edge is also a forward edge.
3. the edge between parent and child is tree edge
   - it is not forward edge and backward edge

### Subtree

In a tree, every node is the root of its corrsponding subtrees.

### Subtree aggregates

If the information is about the biggest subtree with a root, then we will call it subtree aggregate.

For examples:

- the height of subtree
- the nodes of subtree
- the number of nodes of subtree

### Reachable Node

The reachable node of a substree is a node which the subtree can get by only using its own forward and backward edges.

### Lowlink

Lowlink is a subtree aggregate which is the smallest preorder number of reachable nodes.

## Tarjan's Algorithm

```C++
// used to record preorder & postorder number
class Clock
{
  int _time = 0;

public:
  int tick()
  {
    auto ret = _time;
    _time += 1;
    return ret;
  }
};
```

```C++
// main

// graph[i] contains all next nodes of node i
vector<vector<int>> graph(n, vector(0, 0));

// dfs setup and call
vector<int> pre(n, INT_MAX);
vector<int> post(n, INT_MAX);
vector<int> lowlinks(n, 0);
int start = 0;
Clock clock;
dfs(start, clock, graph, pre, post, lowlinks)
```

```C++
// dfs
void dfs(int node, Clock &clock, vector<vector<int>> &graph, vector<int> &pre, vector<int> &post, vector<int> &lowlinks)
{
  auto time = clock.tick();
  pre[node] = time;
  lowlinks[node] = time;

  for (auto child : graph[node])
  {
    // cross edge
    if(post[child] < pre[node])
    {
      continue;
    }

    // tree edge
    if(pre[node] == INT_MAX)
    {
      dfs(child, node, time, graph, times, lowlinks, states);
    }

    // tree edge and forward edge
    if(pre[node] < pre[child])
    {
      lowlinks[node] = min(lowlinks[node], lowlinks[child]);
      return;
    }

    // backward edge
    lowlinks[node] = min(lowlinks[node], pre[child]);
  }

  time = clock.tick();
  postorders[time] = time;
}

```

### Number of Component in Undirected Graph

You can use DFS to determine the number of component of a graph.

Time complexity: `O(V+E)`.

### Cut Edges in Undirected Graph

An edge is a `cut edge` (aka `bridge`) if the number of component increase after removing it.

#### Brute Force Algorithm

1. determine the number of component in the graph
2. removing an edge, and determine if the number of component increase

Time complexity: `O(E(V+E))` for finding all cut edge.

#### Tarjan's Algorithm

For each edge, determine if the lowlink of one node is greater than the preorder number of another node.

Time complexity: `O(E)` for finding all cut vertex.

### Cut Vertex in Undirected Graph

A vertex is a `cut vertex` if the number of component increase after removing it.

#### Brute Force Algorithm

1. determine the number of component in the graph
2. removing a vertex, and determine if the number of component increase

Time complexity: `O(V(V+E))` for finding all cut vertex.

#### Tarjan's Algorithm

For each node:

1. if it is root, check if the number of edges is 1.
2. else check if there exists any lowlink of its neighbours is greater or equal to its preorder number.

Time complexity: `O(V+E)` for finding all cut vertex.

### Strongly Connected Component

- `strongly connected`: A directed graph is `strongly connected` if there is a path between all pairs of vertices.
- `strongly connected component`: A `strongly connected component` (SCC) of a directed graph is a maximal strongly connected subgraph.
- `root of SCC`: The `root of SCC` is the root of subtree (of DFS spanning tree) where they have the same group of nodes.

#### Tarjan's Algorithm

Before DFS precess, we prepare a box.

In the DFS process, for each node:

- put it into the box after visited all its neighbours
- if its lowlink equals to its preorder number, it is the root of SCC,
- if it is the root of SCC, the box become a SCC, and create a new box

### Meta Graph

A meta graph is a graph where:

- the nodes are the SCCs
- the edge from `SCC A` to `SCC B` exists iff there exists a path from `SCC A` to `SCC B`

After we create the strongly connected component, it is easy to create the meta graph.

## Reference

- https://www.youtube.com/watch?v=iYJqgMKYsdI
- https://www.youtube.com/watch?v=TyWtx7q2D7Y
- https://www.youtube.com/watch?v=aZXi1unBdJA
- https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
- https://www.geeksforgeeks.org/strongly-connected-components/
- https://courses.cs.duke.edu/fall17/compsci330/lecture12note.pdf
