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

1. there's no cross edge.
2. there's no forward edge.
3. the edge between parent and child is tree edge

### Subtree

In a tree, every node is the root of its corrsponding subtrees.

### Subtree aggregates

If the information is about the biggest subtree with a root, then we will call it subtree aggregate.

For examples:

- the height of subtree
- the nodes of subtree
- the number of nodes of subtree

### Lowlink

- `lowlink(u)` is the smallest preorder of any node reachable from `u` using zero or more tree edges followed by at most one back or cross edge.
- lowlink is a subtree aggregate.
- notice that, if you want to find the strongly connected components, the definition of `lowlink(u)` should be different.
  - see [wiki](https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm)
  - see [video](https://www.youtube.com/watch?v=wUgWX0nc4NY&t=671s&ab_channel=WilliamFiset)
  - see [handout](https://www.cs.cmu.edu/~15451-f18/lectures/lec19-DFS-strong-components.pdf)

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

For each edge, determine if the lowlink of child is greater than the preorder of parent.

Time complexity: `O(E)` for finding all cut vertex.

### Cut Vertex in Undirected Graph

A vertex is a `cut vertex` if the number of component increase after removing it.

#### Brute Force Algorithm

1. determine the number of component in the graph
2. removing a vertex, and determine if the number of component increase

Time complexity: `O(V(V+E))` for finding all cut vertex.

#### Tarjan's Algorithm

During the DFS process, for each node:

1. if it is root, check if the number of edges is 1.
2. else check if there exists any lowlink of its child is greater or equal to its preorder number.

Time complexity: `O(V+E)` for finding all cut vertex.

### Strongly Connected Component

- `strongly connected`: A directed graph is `strongly connected` if there is a path between all pairs of vertices.
- `strongly connected component`: A `strongly connected component` (SCC) of a directed graph is a maximal strongly connected subgraph.
- `root of SCC`: The `root of SCC` is the root of subtree (of DFS spanning tree) where the SCC and the subtree have the same group of nodes.

#### Tarjan's Algorithm

Actually, the definition of lowlink is different here. You need to maintain a stack to update lowlink.

- see [wiki](https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm)
- see [video](https://www.youtube.com/watch?v=wUgWX0nc4NY&t=671s&ab_channel=WilliamFiset)
- see [handout](https://www.cs.cmu.edu/~15451-f18/lectures/lec19-DFS-strong-components.pdf)

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
