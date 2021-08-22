#include <bits/stdc++.h>

using namespace std;

// comparison between Kruskal’s algorithm and Prim’s algorithm
// Kruskal’s algorithm:
// time complexity: O(E log V) -> faster for sparse graph
// https://www.youtube.com/watch?v=71UQH7Pr9kU&ab_channel=MichaelSambol
//
// Prim’s algorithm:
// time complexity, using Fibonacci heap: O(E + V log V) -> faster for dense graph
// time complexity, using min heap: O(E log V)
// only for undirected graph
// https://www.youtube.com/watch?v=cplfcGZmX7I&ab_channel=MichaelSambol

class UnionFind
{
  vector<int> parents;
  vector<int> sizes;

public:
  UnionFind(int size)
  {
    for (int i = 0; i < size; i++)
    {
      parents.push_back(i);
      sizes.push_back(1);
    }
  }

  int find(int node)
  {
    auto parent = parents[node];
    if (node == parent)
    {
      return node;
    }

    parents[node] = find(parent);
    return parents[node];
  }

  void unite(int node0, int node1)
  {
    auto parent0 = find(node0);
    auto parent1 = find(node1);
    if (parent0 == parent1)
    {
      return;
    }

    if (sizes[parent0] > sizes[parent1])
    {
      sizes[parent0] += sizes[parent1];
      parents[parent1] = parent0;
      return;
    }

    sizes[parent1] += sizes[parent0];
    parents[parent0] = parent1;
  }
};

struct Edge
{
  int node0;
  int node1;
};

class Solution
{
public:
  // implement Kruskal’s algorithm
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    auto numPoints = points.size();

    // graph[i][j]: the weight between node i and node j
    vector<vector<int>> graph(numPoints, vector(numPoints, 0));
    for (auto i = 0; i < numPoints; i++)
    {
      for (auto j = i + 1; j < numPoints; j++)
      {
        auto xi = points[i][0];
        auto yi = points[i][1];
        auto xj = points[j][0];
        auto yj = points[j][1];
        auto distance = abs(xi - xj) + abs(yi - yj);
        graph[i][j] = distance;
        graph[j][i] = distance;
      }
    }

    // store every edge into pq
    auto cmp = [&graph](Edge &edge0, Edge &edge1)
    {
      return graph[edge0.node0][edge0.node1] > graph[edge1.node0][edge1.node1];
    };
    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
    for (auto i = 0; i < numPoints; i++)
    {
      for (auto j = i + 1; j < numPoints; j++)
      {
        pq.push({i, j});
      }
    }

    // union find
    UnionFind unionFind(numPoints);

    // pop edge from pq, use the nodes of edge whose nodes do not in the same set
    int ret = 0;
    int count = 0;
    while (true)
    {
      if (count == numPoints)
      {
        break;
      }
      if (pq.empty())
      {
        break;
      }

      auto [node0, node1] = pq.top();
      pq.pop();
      auto parent0 = unionFind.find(node0);
      auto parent1 = unionFind.find(node1);
      if (parent0 == parent1)
      {
        continue;
      }

      ret += graph[node0][node1];
      count += 1;
      unionFind.unite(node0, node1);
    }

    return ret;
  }
};