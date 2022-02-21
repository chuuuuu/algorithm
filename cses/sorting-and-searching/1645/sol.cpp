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
  for (int i = 0; i < n; i++)
  {
    cin >> xs[i];
  }

  // pair.first = x, pair.second = index
  stack<pair<int, int>> stk;
  for (int i = 0; i < n; i++)
  {
    // deletion
    while (true)
    {
      if (stk.empty() || stk.top().first < xs[i])
      {
        break;
      }
      stk.pop();
    }

    cout << ((stk.empty())? 0 : stk.top().second) << ' ';

    stk.push({xs[i], i + 1});
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}