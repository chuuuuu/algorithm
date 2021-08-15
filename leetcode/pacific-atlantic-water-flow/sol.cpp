#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    auto width = heights.size();
    auto length = heights[0].size();
    vector<vector<bool>> atlantic(width, vector(length, false));
    vector<vector<bool>> pacific(width, vector(length, false));
    this->atlantic(heights, atlantic);
    this->pacific(heights, pacific);

    vector<vector<int>> ret;
    for (auto i = 0; i < width; i++)
    {
      for (auto j = 0; j < length; j++)
      {
        if (atlantic[i][j] && pacific[i][j])
        {
          ret.push_back({i, j});
        }
      }
    }

    return ret;
  }

  void atlantic(vector<vector<int>> &heights, vector<vector<bool>> &atlantic)
  {
    auto width = heights.size();
    auto length = heights[0].size();
    queue<pair<int, int>> q;
    for (auto i = 0; i < width; i++)
    {
      for (auto j = 0; j < length; j++)
      {
        if (i == width - 1 || j == length - 1)
        {
          q.push({i, j});
        }
      }
    }

    this->solver(heights, atlantic, q);
  }

  void pacific(vector<vector<int>> &heights, vector<vector<bool>> &pacific)
  {
    auto width = heights.size();
    auto length = heights[0].size();
    queue<pair<int, int>> q;
    for (auto i = 0; i < width; i++)
    {
      for (auto j = 0; j < length; j++)
      {
        if (i == 0 || j == 0)
        {
          q.push({i, j});
        }
      }
    }

    this->solver(heights, pacific, q);
  }

  void solver(vector<vector<int>> &heights, vector<vector<bool>> &ocean, queue<pair<int, int>> &q)
  {
    auto width = heights.size();
    auto length = heights[0].size();

    vector<vector<bool>> seen(width, vector(length, false));
    vector<pair<int, int>> drs = {{-1, 0},
                                  {1, 0},
                                  {0, -1},
                                  {0, 1}};
    while (!q.empty())
    {
      auto [first, second] = q.front();
      ocean[first][second] = true;
      q.pop();

      for (auto dr : drs)
      {
        auto x = first + dr.first;
        auto y = second + dr.second;
        if (x < 0 || x == width || y < 0 || y == length)
        {
          continue;
        }

        if (heights[x][y] < heights[first][second])
        {
          continue;
        }

        if (seen[x][y])
        {
          continue;
        }
        seen[x][y] = true;

        q.push({x, y});
      }
    }
  }
};