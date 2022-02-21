// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n;
  cin >> n;

  vector<int> as(n, 0);
  vector<int> ds(n, 0);
  for(int i=0; i<n; i++){
    cin >> as[i] >> ds[i];
  }

  sort(as.begin(), as.end());
  ll ans = 0;
  ll s = 0;
  for(int i=0; i<n; i++){
    s += as[i];
    ans += ds[i] - s;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}