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

  vector<int> xs(n, 0);
  for (auto &x : xs)
  {
    cin >> x;
  }

  int xmax = *max_element(xs.begin(), xs.end());

  vector<vector<bool>> dp(n + 1, vector<bool>(xmax * n + 1, false));
  dp[0][0] = true;
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 0; j < xmax * n + 1; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= xs[i - 1])
      {
        dp[i][j] = dp[i][j] || dp[i - 1][j - xs[i - 1]];
      }
    }
  }

  int ans = 0;
  vector<int> ss;
  for (int i = 1; i < xmax * n + 1; i++)
  {
    if(dp[n][i]){
      ans++;
      ss.push_back(i);
    }
  }

  cout << ans << endl;
  for(int s: ss){
    cout << s << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}