#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    auto sum = 0;
    auto count = 0;
    auto minCount = 100001;
    auto head = 0;
    for (auto num : nums)
    {
      sum += num;
      count += 1;
      while (sum >= target)
      {
        if (count < minCount)
        {
          minCount = count;
        }
        sum -= nums[head];
        count -= 1;
        head += 1;
      }
    }

    if (minCount > 100000)
    {
      return 0;
    }

    return minCount;
  }
};