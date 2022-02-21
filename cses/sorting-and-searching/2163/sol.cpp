#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, k;
  cin >> n >> k;
  ordered_set<int> s;
  for (int i = 1; i <= n; i++)
  {
    s.insert(i);
  }

  int pos = 0;
  while (true)
  {
    if(s.empty()){
      break;
    }

    pos = (pos + k) % s.size();
    auto it = s.find_by_order(pos);
    cout << *it << ' ';
    s.erase(it);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
