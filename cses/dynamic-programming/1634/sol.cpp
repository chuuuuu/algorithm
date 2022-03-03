// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int inf = 1e6 + 1;

void solve()
{
  int n, x;
  cin >> n >> x;

  vector<int> coins(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  vector<int> dp(x + 1, inf);
  dp[0] = 0;
  for (int i = 1; i < x + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - coins[j] >= 0)
      {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  cout << ((dp.back() == inf) ? -1 : dp.back());
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}