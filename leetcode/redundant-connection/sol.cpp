#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    vector<int> parents;
    vector<int> sizes;
    for (auto i = 0; i < edges.size(); i++)
    {
      parents.push_back(i);
      sizes.push_back(1);
    }

    for (auto edge : edges)
    {
      auto node0 = edge[0] - 1;
      auto node1 = edge[1] - 1;
      auto parent0 = find(parents, node0);
      auto parent1 = find(parents, node1);
      if (parent0 == parent1)
      {
        return edge;
      }

      auto size0 = sizes[parent0];
      auto size1 = sizes[parent1];
      if (size1 > size0)
      {
        parents[parent0] = parent1;
        sizes[parent1] += size0;
        continue;
      }

      parents[parent1] = parent0;
      sizes[parent0] += size1;
    }

    throw invalid_argument("no redundant connection");
  }

  int find(vector<int> &parents, int node)
  {
    if (node == parents[node])
    {
      return node;
    }
    // do path compression while find
    // in average, time complexity would be come log*(n) which is almost const
    parents[node] = find(parents, parents[node]);
    return parents[node];
  }
};