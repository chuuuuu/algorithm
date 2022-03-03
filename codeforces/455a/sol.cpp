#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N = 100001;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> vec(n, 0);
  for (ll i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  vector<ll> counts(N, 0);
  for (ll i = 0; i < n; i++)
  {
    counts[vec[i]]++;
  }

  vector<ll> dp(N, 0);
  dp[1] = counts[1];
  for (ll i = 2; i < N; i++)
  {
    dp[i] = max(dp[i-1], counts[i] * i + dp[i - 2]);
  }

  cout << dp.back() << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}