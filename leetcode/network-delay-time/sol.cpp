// https://www.youtube.com/watch?v=pVfj6mxhdMw&t=553s&ab_channel=ComputerScience
// time complexity: O(E * log(V))

// notes:
// Bellman algorithm can also solve this problem
// moreover, Bellman algorithm can handle graph with nagative weights which Dijkstra algorithm can't
// however, time complexity will be O(VE)

#include <bits/stdc++.h>

using namespace std;

struct Data
{
  int targetNode;
  int weight;
};

class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    // given nodes start from 1, but we start from 0
    k = k - 1;

    vector<vector<Data>> graph(n, vector<Data>(0, {0, 0}));
    for (auto edge : times)
    {
      auto sourceNode = edge[0] - 1;
      auto targetNode = edge[1] - 1;
      auto weight = edge[2];

      graph[sourceNode].push_back({targetNode, weight});
    }

    vector<int> distances(n, INT_MAX);
    distances[k] = 0;
    auto cmp = [&distances](int node0, int node1)
    {
      return distances[node0] > distances[node1];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(k);
    unordered_set<int> isVisit;
    while (true)
    {
      if (pq.empty())
      {
        break;
      }
      auto node = pq.top();
      pq.pop();

      if (isVisit.count(node))
      {
        continue;
      }

      isVisit.insert(node);

      for (auto [neightbour, weight] : graph[node])
      {
        distances[neightbour] = min(distances[neightbour], distances[node] + weight);
        if (isVisit.count(neightbour))
        {
          continue;
        }

        pq.push(neightbour);
      }
    }

    auto ret = INT_MIN;
    for (auto distance : distances)
    {
      if (distance == INT_MAX)
      {
        return -1;
      }

      ret = max(ret, distance);
    }

    return ret;
  }
};