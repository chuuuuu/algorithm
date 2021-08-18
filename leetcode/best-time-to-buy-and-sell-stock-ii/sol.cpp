#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    auto ret = 0;
    for (auto i = 1; i < prices.size(); i++)
    {
      ret += max(0, prices[i] - prices[i - 1]);
    }

    return ret;
  }
};