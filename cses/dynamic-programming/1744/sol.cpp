// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int a, b;
  cin >> a >> b;

  vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
  for (int i = 1; i < a + 1; i++)
  {
    for (int j = 1; j < b + 1; j++)
    {
      if (i == j)
      {
        dp[i][j] = 0;
        continue;
      }

      for (int k = 1; k < i; k++)
      {
        dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
      }

      for (int k = 1; k < j; k++)
      {
        dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
      }
    }
  }

  cout << dp[a][b];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}