// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> as;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    as.push_back({a, i + 1});
  }

  sort(as.begin(), as.end());
  for (int i = 0; i < n - 2; i++)
  {
    int target = x - as[i].first;
    int left = i + 1;
    int right = n - 1;
    while (true)
    {
      if (left == right)
      {
        break;
      }
      if (as[left].first + as[right].first == target)
      {
        cout << as[i].second << ' ' << as[left].second << ' ' << as[right].second;
        return;
      }
      if (as[left].first + as[right].first > target)
      {
        right--;
        continue;
      }
      left++;
    }
  }

  cout << "IMPOSSIBLE";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}