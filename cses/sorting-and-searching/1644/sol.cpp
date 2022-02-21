// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> xs(n, 0);
  vector<ll> pres(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> xs[i];
    pres[i + 1] = pres[i] + xs[i];
  }

  multiset<ll> ms;
  ll ans = LLONG_MIN;
  for (int i = a; i < n + 1; i++)
  {
    ms.insert(pres[i - a]);
    ans = max(ans, pres[i] - *ms.begin());
    if (i >= b)
    {
      ms.erase(ms.find(pres[i - b]));
    }
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}