#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<int> xs(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> xs[i];
  }

  ordered_multiset<int> om;
  for (int i = 0; i < n; i++)
  {
    om.insert(xs[i]);
    if (i >= k - 1)
    {
      int median = *om.find_by_order((k - 1) / 2);
      cout << median << ' ';
      om.erase(om.find_by_order(om.order_of_key(xs[i + 1 - k])));
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}