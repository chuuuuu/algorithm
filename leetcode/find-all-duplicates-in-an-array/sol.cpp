#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    nums.push_back(0);
    auto addon = nums.size() * 2;
    for (auto num : nums)
    {
      nums[num % addon] += addon;
    }

    vector<int> ret;
    for (auto i = 1; i < nums.size(); i++)
    {
      if (nums[i] >= 2 * addon)
      {
        ret.push_back(i);
      }
    }

    return ret;
  }
};