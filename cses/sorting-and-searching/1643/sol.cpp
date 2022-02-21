#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;

  vector<ll> vec;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  vector<ll> dp(n + 1, 0);
  ll ans = vec[0];
  for (int i = 0; i < n; i++)
  {
    dp[i + 1] = max(dp[i] + vec[i], vec[i]);
    ans = max(ans, dp[i + 1]);
  }

  cout << ans;
  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}