#include <bits/stdc++.h>

using namespace std;

// buy[0][i] = -prices[i]
// hold[0][i] = max(buy[0][i-1], hold[0][i-1])

// sell[0][i] = max(buy[0][i-1], hold[0][i-1]) + prices[i]
// sold[0][i] = max(sell[0][i-1], sold[0][i-1])

// buy[1][i] = max(sell[0][i-1], sold[0][i-1]) - prices[i]
// hold[1][i] = max(buy[1][i-1], hold[1][i-1])

// sell[1][i] = max(buy[1][i-1], hold[1][i-1]) + prices[i]
// sold[1][i] = max(sell[1][i-1], sold[1][i-1])

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    auto size = prices.size();
    vector<vector<int>> buy(2, vector(size, -prices[0]));
    vector<vector<int>> hold(2, vector(size, -prices[0]));
    vector<vector<int>> sell(2, vector(size, 0));
    vector<vector<int>> sold(2, vector(size, 0));
    for (auto i = 1; i < size; i++)
    {
      buy[0][i] = -prices[i];
      hold[0][i] = max(buy[0][i - 1], hold[0][i - 1]);

      sell[0][i] = max(buy[0][i - 1], hold[0][i - 1]) + prices[i];
      sold[0][i] = max(sell[0][i - 1], sold[0][i - 1]);

      buy[1][i] = max(sell[0][i - 1], sold[0][i - 1]) - prices[i];
      hold[1][i] = max(buy[1][i - 1], hold[1][i - 1]);

      sell[1][i] = max(buy[1][i - 1], hold[1][i - 1]) + prices[i];
      sold[1][i] = max(sell[1][i - 1], sold[1][i - 1]);
    }

    return max(sell[1].back(), sold[1].back());
  }
};