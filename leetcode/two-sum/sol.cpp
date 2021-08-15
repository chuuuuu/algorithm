#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> numMap;
    for (auto i = 0; i < nums.size(); i++)
    {
      if (numMap.count(target - nums[i]))
      {
        return {numMap[target - nums[i]], i};
      }

      numMap[nums[i]] = i;
    }

    throw invalid_argument("solution not found\n");
  }
};