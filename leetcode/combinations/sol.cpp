#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // combine(n, k) = combine(n-1, k) + combine(n-1, k-1)
  vector<vector<int>> combine(int n, int k)
  {
    if (n < k)
    {
      return {};
    }

    if (k == 1)
    {
      vector<vector<int>> ret;
      for (int i = 1; i <= n; i++)
      {
        ret.push_back({i});
      }

      return ret;
    }

    auto combs = combine(n - 1, k);
    for (auto comb : combine(n - 1, k - 1))
    {
      comb.push_back(n);
      combs.push_back(comb);
    }

    return combs;
  }
};