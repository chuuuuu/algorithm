#include <bits/stdc++.h>

using namespace std;

// 01234
// 40123
// 34012
// 23401
// 12340

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return nums[0];
    }
    return findMin(nums, 0, nums.size() - 1);
  }

  int findMin(vector<int> &nums, int head, int tail)
  {
    if (nums[tail] > nums[head])
    {
      return nums[head];
    }

    if (head + 1 == tail)
    {
      return min(nums[head], nums[tail]);
    }

    int middle = (head + tail) / 2;
    if (nums[head] > nums[middle])
    {
      return findMin(nums, head, middle);
    }

    return findMin(nums, middle, tail);
  }
};