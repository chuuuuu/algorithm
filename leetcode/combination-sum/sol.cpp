#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    if (!target)
    {
      return {{}};
    }

    if (candidates.size() == 0)
    {
      return {};
    }

    vector<vector<int>> ret;
    auto back = candidates.back();
    candidates.pop_back();
    for (auto comb : combinationSum(candidates, target))
    {
      ret.push_back(comb);
    }

    candidates.push_back(back);
    if (target >= candidates.back())
    {
      for (auto comb : combinationSum(candidates, target - back))
      {
        comb.push_back(back);
        ret.push_back(comb);
      }
    }

    return ret;
  }
};