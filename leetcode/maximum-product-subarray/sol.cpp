#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    auto ret = nums[0];
    auto maxProd = nums[0];
    auto minProd = nums[0];
    for (auto i = 1; i < nums.size(); i++)
    {
      auto num = nums[i];
      auto maxProdNew = max(max(num, maxProd * num), minProd * num);
      auto minProdNew = min(min(num, maxProd * num), minProd * num);

      maxProd = maxProdNew;
      minProd = minProdNew;

      ret = max(maxProd, ret);
    }

    return ret;
  }
};