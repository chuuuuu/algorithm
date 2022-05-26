// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;

ll myPow(ll a, ll b)
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
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << myPow(a, b) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}