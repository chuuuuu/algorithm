#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    auto size = graph.size();
    vector<vector<int>> reverseGraph(size, vector(0, 0));
    for (auto i = 0; i < size; i++)
    {
      for (auto j = 0; j < graph[i].size(); j++)
      {
        reverseGraph[graph[i][j]].push_back(i);
      }
    }

    vector<int> outdeg(size, 0);
    queue<int> q;
    for (auto i = 0; i < size; i++)
    {
      outdeg[i] = graph[i].size();
      if (!outdeg[i])
      {
        q.push(i);
      }
    }

    while (true)
    {
      if (q.empty())
      {
        break;
      }

      auto node = q.front();
      q.pop();

      for (auto newNode : reverseGraph[node])
      {
        outdeg[newNode] -= 1;
        if (!outdeg[newNode])
        {
          q.push(newNode);
        }
      }
    }

    vector<int> ret;
    for (auto i = 0; i < size; i++)
    {
      if (!outdeg[i])
      {
        ret.push_back(i);
      }
    }

    return ret;
  }
};