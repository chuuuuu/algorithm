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

  vector<ll> as(n, 0);
  vector<ll> pres(n + 1, 0);
  for (ll i = 0; i < n; i++)
  {
    cin >> as[i];
    pres[i + 1] = pres[i] + as[i];
  }

  map<ll, ll> mp;
  ll ans = 0;
  for (ll i = 0; i < n + 1; i++)
  {
    ll pre = pres[i];
    ll target = pre - x;
    if(mp.count(target)){
      ans += mp[target];
    }

    if(!mp.count(pre)){
      mp[pre] = 0;
    }

    mp[pre]++;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}