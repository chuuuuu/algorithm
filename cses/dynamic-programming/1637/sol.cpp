// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n;
  cin >> n;

  vector<int> dp(n + 1, 1e6 + 1);
  dp[0] = 0;
  for (int i = 1; i < n + 1; i++)
  {
    int x = i;
    while (true)
    {
      if(x == 0){
        break;
      }

      int digit = x % 10;
      x /= 10;
      if (i - digit >= 0)
      {
        dp[i] = min(dp[i], dp[i - digit] + 1);
      }
    }
  }

  cout << dp[n];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}