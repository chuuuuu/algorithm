// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define mod 1000000007;

void solve()
{
  int n, x;
  cin >> n >> x;

  vector<int> cs(n, 0);
  for (int &c : cs)
  {
    cin >> c;
  }

  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i < x + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i >= cs[j])
      {
        dp[i] = dp[i] + dp[i - cs[j]];
        dp[i] = dp[i] % mod;
      }
    }
  }

  cout << dp[x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}