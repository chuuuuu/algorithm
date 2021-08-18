#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, k, p;
  cin >> n >> k >> p;

  vector<vector<int>> b(n + 1, vector(k + 1, 0));
  for (auto i = 1; i < n + 1; i++)
  {
    for (auto j = 1; j < k + 1; j++)
    {
      cin >> b[i][j];
    }
  }

  vector<vector<int>> bs(n + 1, vector(k + 1, 0));
  for (auto i = 1; i < n + 1; i++)
  {
    for (auto j = 1; j < k + 1; j++)
    {
      bs[i][j] = bs[i][j - 1] + b[i][j];
    }
  }

  vector<vector<int>> dp(n + 1, vector(p + 1, 0));
  for (auto i = 1; i < n + 1; i++)
  {
    for (auto j = 1; j < p + 1; j++)
    {
      for (auto l = 0; l < min(j + 1, k + 1); l++)
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + bs[i][l]);
      }
    }
  }

  auto ans = dp.back().back();
  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}