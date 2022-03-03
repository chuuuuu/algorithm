// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  ll n, x;
  cin >> n >> x;

  vector<ll> ws(n, 0);
  for (ll &w : ws)
  {
    cin >> w;
  }

  vector<ll> minRides(1 << n, LLONG_MAX);
  vector<ll> minWeights(1 << n, LLONG_MAX);
  minRides[0] = 0;
  minWeights[0] = x;
  for (ll i = 1; i < (1 << n); i++)
  {
    for (ll j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        ll minRide, minWeight;
        if (minWeights[i ^ (1 << j)] + ws[j] <= x)
        {
          minRide = minRides[i ^ (1 << j)];
          minWeight = minWeights[i ^ (1 << j)] + ws[j];
        }
        else
        {
          minRide = minRides[i ^ (1 << j)] + 1;
          minWeight = ws[j];
        }

        if (minRide < minRides[i] || (minRide == minRides[i] && minWeight < minWeights[i]))
        {
          minRides[i] = minRide;
          minWeights[i] = minWeight;
        }
      }
    }
  }

  cout << minRides.back();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}