#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// count how many 5 are there
void solve()
{
  ll n;
  cin >> n;

  // avoid floating precision problem
  ll maxPower = log(n) / log(5) + 1;
  ll power5 = 5;
  vector<ll> counts(maxPower + 1, 0);
  for (ll i = 1; i <= maxPower; i++)
  {
    counts[i] = n / power5;
    power5 *= 5;
  }

  ll ans = 0;
  for (int i = 1; i <= maxPower; i++)
  {
    ans += counts[i];
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}