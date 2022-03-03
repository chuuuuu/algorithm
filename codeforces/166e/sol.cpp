#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// f(5) = 3 * (-1) * ((-3)^4 - 1) / (-3 - 1) = 3 * (3 ^ 4 - 1) / 4
// f(6) = 3 * (1) * ((-3)^5 - 1) / (-3 - 1) = 3 * (3 ^ 5 + 1) / 4
void solve()
{
  ll n;
  cin >> n;
  ll ans = 1;
  ll mod = 1e9+7;
  for (ll i = 0; i < n - 1; i++)
  {
    ans *= 3;
    ans %= (mod * 4);
  }

  if (n % 2 == 1)
  {
    ans = 3 * (ans - 1) / 4;
    ans %= mod;
    cout << ans << endl;
    return;
  }

  ans = 3 * (ans + 1) / 4;
  ans %= mod;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}