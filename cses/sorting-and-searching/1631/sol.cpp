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

  vector<int> ts(n, 0);
  ll s = 0;
  int maxT = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> ts[i];
    s += ts[i];
    maxT = max(maxT, ts[i]);
  }

  cout << ((2 * maxT > s) ? (2 * maxT) : s);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}