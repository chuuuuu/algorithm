#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    auto minPrice = INT_MAX;
    auto maxProfit = 0;
    for (auto i = 0; i < prices.size(); i++)
    {
      minPrice = min(prices[i], minPrice);
      maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
  }
};