#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    auto sum = 0;
    for (auto num : nums)
    {
      sum += num;
    }

    // if sum is odd
    if (sum & 1)
    {
      return false;
    }

    // if we can find a set of num, numSet, in nums such that numSet.sum() is sum / 2.
    // then nums is guarantee to be partitioned

    auto range = nums.size() + 1;
    auto target = sum / 2 + 1;
    bool dp[range][target];
    for (auto i = 0; i < range; i++)
    {
      for (auto j = 0; j < target; j++)
      {
        if (j == 0)
        {
          dp[i][j] = true;
          continue;
        }

        dp[i][j] = false;
      }
    }

    for (auto i = 1; i < range; i++)
    {
      for (auto j = 1; j < target; j++)
      {
        if (j >= nums[i - 1])
        {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
          continue;
        }

        dp[i][j] = dp[i - 1][j];
      }
    }
    
    return dp[range - 1][target - 1];
  }
};