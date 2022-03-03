// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<int> hs(n, 0);
  for (auto &h : hs)
  {
    cin >> h;
  }

  vector<int> ss(n, 0);
  for (auto &s : ss)
  {
    cin >> s;
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < x + 1; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= hs[i - 1])
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - hs[i - 1]] + ss[i - 1]);
      }
    }
  }

  cout << dp[n][x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}