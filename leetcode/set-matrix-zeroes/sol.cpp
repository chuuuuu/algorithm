#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    unordered_set<int> colSet;
    unordered_set<int> rowSet;
    for (auto i = 0; i < matrix.size(); i++)
    {
      for (auto j = 0; j < matrix[0].size(); j++)
      {
        if (!matrix[i][j])
        {
          colSet.insert(i);
          rowSet.insert(j);
        }
      }
    }

    for (auto i = 0; i < matrix.size(); i++)
    {
      for (auto j = 0; j < matrix[0].size(); j++)
      {
        if (colSet.count(i) || rowSet.count(j))
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};