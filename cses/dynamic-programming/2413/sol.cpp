// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;

int N = 1e6;
vector<ll> as(N, 0);
vector<ll> bs(N, 0);

void build()
{
  as[0] = 1;
  bs[0] = 1;
  for (int i = 1; i < N; i++)
  {
    as[i] = 4 * as[i - 1] + bs[i - 1];
    as[i] %= mod;
    bs[i] = as[i - 1] + 2 * bs[i - 1];
    bs[i] %= mod;
  }
}

void solve()
{
  int n;
  cin >> n;
  cout << (as[n - 1] + bs[n - 1]) % mod << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  build();

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
}