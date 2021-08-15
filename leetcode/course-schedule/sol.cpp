#include <bits/stdc++.h>

using namespace std;
// input:
// numCourses: 6
// prerequisites: [[1, 0], [5, 3], [2, 3], [3, 4]]
// 0 -- 1
// 4 -- 3 -- 5
//      + -- 2

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> indegrees(numCourses, 0);
    vector<vector<int>> edges(numCourses);
    for (auto prerequisite : prerequisites)
    {
      indegrees[prerequisite[0]] += 1;
      edges[prerequisite[1]].push_back(prerequisite[0]);
    }

    queue<int> q;
    for (auto i = 0; i < numCourses; i++)
    {
      if (!indegrees[i])
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      auto from = q.front();
      q.pop();
      for (auto to : edges[from])
      {
        indegrees[to] -= 1;
        if (!indegrees[to])
        {
          q.push(to);
        }
      }
    }

    for (auto indegree : indegrees)
    {
      if (indegree)
      {
        return false;
      }
    }

    return true;
  }
};