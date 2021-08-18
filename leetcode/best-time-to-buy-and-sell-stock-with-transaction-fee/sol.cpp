#include <bits/stdc++.h>

using namespace std;

// buy[i] = max(sell[i-1], sold[i-1]) - price[i]
// hold[i] = max(buy[i-1], hold[i-1])
// sell[i] = max(buy[i-1], hold[i-1]) + price[i] - fee
// sold[i] = max(sell[i-1], sold[i-1])

class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    auto size = prices.size();
    vector<int> sell(size, 0);
    vector<int> sold(size, 0);
    vector<int> buy(size, -prices[0]);
    vector<int> hold(size, -prices[0]);

    for (auto i = 1; i < size; i++)
    {
      buy[i] = max(sell[i - 1], sold[i - 1]) - prices[i];
      hold[i] = max(buy[i - 1], hold[i - 1]);
      sell[i] = max(buy[i - 1], hold[i - 1]) + prices[i] - fee;
      sold[i] = max(sell[i - 1], sold[i - 1]);
    }

    return max(sold.back(), sell.back());
  }
};