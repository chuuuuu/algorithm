#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    auto ret = 0;
    for(auto num: nums){
      ret ^= num;
    }

    return ret;
  }
};