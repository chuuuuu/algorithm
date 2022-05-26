// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, q;
  cin >> n >> q;

  vector<int> xs(n + 1);
  vector<ll> pres(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    cin >> xs[i];
    pres[i] = pres[i - 1] + xs[i];
  }

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;

    cout << pres[b] - pres[a - 1] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}