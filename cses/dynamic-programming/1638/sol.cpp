// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9+7;

void solve()
{
  int n;
  cin >> n;

  vector<vector<char>> mp(n + 1, vector<char>(n + 1, '*'));
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      cin >> mp[i][j];
    }
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[1][1] = (mp[1][1] == '.');
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      if (i == 1 && j == 1)
      {
        continue;
      }
      if (mp[i][j] == '*')
      {
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }

  cout << dp[n][n];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}