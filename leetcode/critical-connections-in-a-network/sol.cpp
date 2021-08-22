#include <bits/stdc++.h>
using namespace std;

// Tarjan's Algorithm
// time complexity: O(E)

class Clock
{
  int _time;

public:
  Clock() : _time(0)
  {
  }

  int tick()
  {
    auto ret = _time;
    _time += 1;
    return ret;
  }
};

class Solution
{
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {
    // build the graph
    vector<vector<int>> graph(n, vector(0, 0));
    for (auto connection : connections)
    {
      auto node0 = connection[0];
      auto node1 = connection[1];
      graph[node0].push_back(node1);
      graph[node1].push_back(node0);
    }

    // dfs setup and call
    vector<int> preorders(n, -1);
    vector<int> lowlinks(n, 0);
    Clock clock;
    int start = 0;
    int parent = -1;
    dfs(start, parent, clock, graph, preorders, lowlinks);

    vector<vector<int>> ret;
    for (auto connection : connections)
    {
      auto node0 = connection[0];
      auto node1 = connection[1];
      if (lowlinks[node0] > preorders[node1] || lowlinks[node1] > preorders[node0])
      {
        ret.push_back({node0, node1});
      }
    }

    return ret;
  }

  void dfs(int node, int parent, Clock &clock, vector<vector<int>> &graph, vector<int> &preorders, vector<int> &lowlinks)
  {
    auto time = clock.tick();

    preorders[node] = time;
    lowlinks[node] = time;
    for (auto child : graph[node])
    {
      // we dont update lowlink from parent
      if (child == parent)
      {
        continue;
      }

      // forward edge
      if (preorders[child] == -1)
      {
        dfs(child, node, clock, graph, preorders, lowlinks);
        lowlinks[node] = min(lowlinks[node], lowlinks[child]);
        continue;
      }

      // backward edge
      lowlinks[node] = min(lowlinks[node], preorders[child]);
    }
  }
};