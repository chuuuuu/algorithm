#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> subsets(vector<int> const &nums)
  {
    if (!nums.size())
    {
      return {{}};
    }
    auto sets = subsets({nums.begin(), nums.end() - 1});
    auto ret = sets;
    for (auto set : sets)
    {
      set.push_back(nums.back());
      ret.push_back(set);
    }

    return ret;
  }
};