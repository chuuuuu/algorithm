#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    for (auto num : nums)
    {
      auto idx = abs(num) - 1;
      if (nums[idx] > 0)
      {
        nums[idx] *= -1;
      }
    }

    vector<int> ret;
    for (auto i = 0; i < nums.size(); i++)
    {
      auto num = nums[i];
      if (num > 0)
      {
        ret.push_back(i + 1);
      }
    }

    return ret;
  }
};