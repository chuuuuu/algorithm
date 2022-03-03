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

  vector<int> xs(n, 0);
  for (int &x : xs)
  {
    cin >> x;
  }

  vector<int> dp = {xs[0]};
  for (int x : xs)
  {
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end())
    {
      dp.push_back(x);
    }
    else
    {
      *it = x;
    }
  }

  cout << dp.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}