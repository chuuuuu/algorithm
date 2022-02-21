#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll n;
  cin >> n;
  ll mod = 1e9+7;
  ll m = 2;
  ll ans = 1;
  // calculate 2 ** n
  while (true)
  {
    if (n == 0)
    {
      break;
    }

    if ((n & 1) == 1)
    {
      ans *= m;
      ans %= mod;
    }

    m *= m;
    m %= mod;
    n /= 2;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}