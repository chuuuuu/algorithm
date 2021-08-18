#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    if (prices.empty() || !k)
    {
      return 0;
    }

    auto size = prices.size();
    vector<vector<int>> buy(k, vector(size, -prices[0]));
    vector<vector<int>> hold(k, vector(size, -prices[0]));
    vector<vector<int>> sell(k, vector(size, 0));
    vector<vector<int>> sold(k, vector(size, 0));
    for (auto i = 1; i < size; i++)
    {
      for (auto j = 0; j < k; j++)
      {
        if (j == 0)
        {
          buy[j][i] = -prices[i];
        }
        else
        {
          buy[j][i] = max(sell[j - 1][i - 1], sold[j - 1][i - 1]) - prices[i];
        }

        hold[j][i] = max(buy[j][i - 1], hold[j][i - 1]);
        sell[j][i] = max(buy[j][i - 1], hold[j][i - 1]) + prices[i];
        sold[j][i] = max(sell[j][i - 1], sold[j][i - 1]);
      }
    }

    return max(sell.back().back(), sold.back().back());
  }
};