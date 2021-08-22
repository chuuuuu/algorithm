#include <bits/stdc++.h>
using namespace std;

// unvisit
#define WHITE 0
// two party
#define BLUE 1
#define RED 2

class Solution
{
public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {
    // graph[i]: neighbours of i
    vector<vector<int>> graph(n, vector(0, 0));
    for (auto dislike : dislikes)
    {
      auto node0 = dislike[0] - 1;
      auto node1 = dislike[1] - 1;
      graph[node0].push_back(node1);
      graph[node1].push_back(node0);
    }

    vector<int> colors(n, WHITE);
    for (auto i = 0; i < n; i++)
    {
      if (colors[i] != WHITE)
      {
        continue;
      }

      colors[i] = RED;
      for (auto neightbour : graph[i])
      {
        if(!dfs(neightbour, BLUE, graph, colors)){
          return false;
        }
      }
    }

    return true;
  }

  // return if valid
  bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &colors)
  {
    if (colors[node] == WHITE)
    {
      colors[node] = color;
      for (auto neightbour : graph[node])
      {
        if(!dfs(neightbour, color == BLUE ? RED : BLUE, graph, colors)){
          return false;
        }
      }
    }

    return colors[node] == color;
  }
};