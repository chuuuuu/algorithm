// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;

void solve()
{
  int n;
  cin >> n;

  int s = n * (n + 1) / 2;
  if (s % 2 == 1)
  {
    cout << 0;
    return;
  }

  int target = s / 2;
  // we always put n to second set
  vector<vector<int>> dp(n, vector<int>(target + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < target + 1; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= i)
      {
        dp[i][j] += dp[i - 1][j - i];
        dp[i][j] %= mod;
      }
    }
  }

  cout << dp[n - 1][target];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}