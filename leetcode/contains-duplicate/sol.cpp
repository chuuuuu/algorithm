#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_set<int> numSet;
    for (auto num : nums)
    {
      if (numSet.count(num))
      {
        return true;
      }

      numSet.insert(num);
    }

    return false;
  }
};