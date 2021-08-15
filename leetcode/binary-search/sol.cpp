#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    auto head = 0;
    auto tail = nums.size();
    while (true)
    {
      auto index = (head + tail) / 2;
      if (nums[index] == target)
      {
        return index;
      }

      if (index == head)
      {
        return -1;
      }

      if(nums[index] > target){
        tail = index;
        continue;
      }

      head = index;
    }
  }
};