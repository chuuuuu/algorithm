// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9+7;

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<int> xs(n, 0);
  for (auto &x : xs)
  {
    cin >> x;
  }

  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    if (xs[0] == 0 || xs[0] == i + 1)
    {
      dp[i][0] = 1;
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (xs[i] == 0 || xs[i] == j + 1)
      {
        dp[j][i] = dp[j][i - 1];
        if (j > 0)
        {
          dp[j][i] += dp[j - 1][i - 1];
          dp[j][i] %= mod;
        }
        if (j < m - 1)
        {
          dp[j][i] += dp[j + 1][i - 1];
          dp[j][i] %= mod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    ans += dp[i].back();
    ans %= mod;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}