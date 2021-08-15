#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());

    auto minDiff = 20000;
    auto sum = 0;
    for (auto i = 0; i < nums.size() - 2; i++)
    {
      auto j = i + 1;
      auto k = nums.size() - 1;
      if (j == k)
      {
        break;
      }

      auto subTarget = target - nums[i];
      while (true)
      {
        if (j == k)
        {
          break;
        }

        auto diff = subTarget - nums[j] - nums[k];
        if (abs(diff) < minDiff)
        {
          minDiff = abs(diff);
          sum = nums[i] + nums[j] + nums[k];
        }

        if (diff == 0)
        {
          return target;
        }

        if (diff < 0)
        {
          k -= 1;
        }

        // diff > 0
        else
        {
          j += 1;
        }
      }
    }

    return sum;
  }
};