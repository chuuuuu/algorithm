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
  vector<int> dp = {0, 0, 0, 0, 0, 1};
  for (int i = 0; i < n; i++)
  {
    int numWays = 0;
    for (int j = 0; j < 6; j++)
    {
      numWays += dp[i + j];
      numWays %= mod;
    }
    dp.push_back(numWays);
  }

  cout << dp.back();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}