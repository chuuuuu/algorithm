#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    auto up = lower_bound(nums.begin(), nums.end(), target);
    if (*up != target)
    {
      return -1;
    }

    return up - nums.begin();
  }
};