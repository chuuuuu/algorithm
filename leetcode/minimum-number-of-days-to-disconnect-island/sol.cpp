#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minDays(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();

    int numNode = 0;
    vector<vector<int>> posToId(m, vector<int>(n, 0));
    for (int x = 0; x < m; x++)
    {
      for (int y = 0; y < n; y++)
      {
        if (grid[x][y])
        {
          posToId[x][y] = numNode;
          numNode++;
        }
      }
    }

    if (numNode == 0)
    {
      return 0;
    }

    if (numNode == 1)
    {
      return 1;
    }

    vector<vector<int>> edges(numNode, vector<int>());
    for (int x = 0; x < m; x++)
    {
      for (int y = 0; y < n; y++)
      {
        int node = posToId[x][y];

        if (!grid[x][y])
        {
          continue;
        }

        vector<vector<int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dr : drs)
        {
          int dx = dr[0];
          int dy = dr[1];
          if (x + dx < 0 || x + dx >= m)
          {
            continue;
          }
          if (y + dy < 0 || y + dy >= n)
          {
            continue;
          }
          if (!grid[x + dx][y + dy])
          {
            continue;
          }

          int neighbour = posToId[x + dx][y + dy];
          edges[node].push_back(neighbour);
        }
      }
    }

    // return 0 if there are more than one island
    if (!isOneIsland(edges))
    {
      return 0;
    }

    // return 1 if there is an articulation point
    if (existCutVertex(edges))
    {
      return 1;
    }

    return 2;
  }

  bool existCutVertex(vector<vector<int>> &edges)
  {
    int numNode = edges.size();
    vector<int> preorders(numNode, -1);
    vector<int> lowlinks(numNode, 0);
    vector<vector<int>> dfsEdges(numNode, vector<int>());
    int clock = 0;
    int root = 0;
    int parent = -1;
    dfs(edges, root, parent, preorders, lowlinks, dfsEdges, clock);

    if (dfsEdges[0].size() > 1)
    {
      return true;
    }

    for (int i = 1; i < numNode; i++)
    {
      for (int neighbour : dfsEdges[i])
      {
        if (lowlinks[neighbour] >= preorders[i])
        {
          return true;
        }
      }
    }

    return false;
  }

  void dfs(vector<vector<int>> &edges, int node, int parent, vector<int> &preorders, vector<int> &lowlinks, vector<vector<int>> &dfsEdges, int &clock)
  {
    preorders[node] = clock;
    lowlinks[node] = clock;
    clock++;

    for (auto neighbour : edges[node])
    {
      // we dont update lowlink from parent
      if (parent == neighbour)
      {
        continue;
      }

      // tree edges
      if (preorders[neighbour] == -1)
      {
        dfsEdges[node].push_back(neighbour);
        dfs(edges, neighbour, node, preorders, lowlinks, dfsEdges, clock);
        lowlinks[node] = min(lowlinks[node], lowlinks[neighbour]);
        continue;
      }

      // front edges + backward edges
      lowlinks[node] = min(lowlinks[node], preorders[neighbour]);
    }
  }

  bool isOneIsland(vector<vector<int>> &edges)
  {
    int numNode = edges.size();
    unordered_set<int> seen;
    int islandNum = 0;
    for (int i = 0; i < numNode; i++)
    {
      if (seen.count(i))
      {
        continue;
      }

      if (islandNum > 0)
      {
        return false;
      }

      dfs(edges, i, seen);
      islandNum++;
    }

    return true;
  }

  void dfs(vector<vector<int>> &edges, int node, unordered_set<int> &seen)
  {
    seen.insert(node);
    for (int neighbour : edges[node])
    {
      if (seen.count(neighbour))
      {
        continue;
      }

      dfs(edges, neighbour, seen);
    }
  }
};