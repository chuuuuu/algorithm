// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll myPow(ll a, ll b, ll mod)
{
  ll ret = 1;
  while (true)
  {
    if (b == 0)
    {
      break;
    }
    
    if (b & 1)
    {
      ret *= a;
      ret %= mod;
    }
    b = b >> 1;
    a *= a;
    a %= mod;
  }

  return ret;
}

void solve()
{
  ll n;
  cin >> n;

  map<ll, ll> primeCnts;
  ll prime = 2;
  while (true)
  {
    if (n == 1)
    {
      break;
    }

    if (n % prime == 0)
    {
      n /= prime;
      primeCnts[prime]++;
      continue;
    }

    prime += 1;
    if (prime * prime > n)
    {
      break;
    }
  }

  ll ans = 1;
  int mod = 1e9 + 7;
  for (auto [prime, cnt] : primeCnts)
  {
    ans *= (myPow(prime, cnt - 1, mod) - 1) / (prime - 1);
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}