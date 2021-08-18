#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    nums.push_back(0);
    auto size = nums.size();

    for (auto i = 0; i < size; i++)
    {
      if (nums[i] < 0 || nums[i] >= size)
      {
        nums[i] = 0;
      }
    }

    for (auto num : nums)
    {
      if (num % size)
      {
        nums[num % size] += size;
      }
    }

    for (auto i = 1; i < size; i++)
    {
      if (nums[i] < size)
      {
        return i;
      }
    }

    return size;
  }
};