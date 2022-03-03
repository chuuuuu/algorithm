// reference / algorithm explanation: https://codeforces.com/blog/entry/90841

// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;

void solve()
{
  int n, m;
  cin >> n >> m;

  int maskSize = n + 1;

  vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(1 << maskSize, 0)));
  dp[0][n][0] = 1;
  for (int i = 1; i < m + 1; i++)
  {
    // we dont want domino out of board, hence mask < (1 << (maskSize - 1))
    for (int mask = 0; mask < (1 << (maskSize - 1)); mask++)
    {
      int newMask = mask << 1;
      dp[i][0][newMask] += dp[i - 1][n][mask];
      dp[i][0][newMask] %= mod;
    }

    for (int j = 1; j < n + 1; j++)
    {
      for (int mask = 0; mask < (1 << maskSize); mask++)
      {
        bool down = mask & (1 << (j - 1));
        bool right = mask & (1 << j);
        if (!down && !right)
        {
          dp[i][j][mask] = dp[i][j - 1][mask ^ (1 << (j - 1))] + dp[i][j - 1][mask ^ (1 << j)];
          dp[i][j][mask] %= mod;
        }
        if (down && !right)
        {
          dp[i][j][mask] = dp[i][j - 1][mask ^ (1 << (j - 1))];
        }
        if (!down && right)
        {
          dp[i][j][mask] = dp[i][j - 1][mask ^ (1 << j)];
        }
      }
    }
  }

  cout << dp[m][n][0];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}