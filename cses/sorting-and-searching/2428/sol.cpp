// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<int> xs(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> xs[i];
  }

  ll ans = 0;
  map<int, int> mp;
  for (int left = 0, right = 0; right < n; right++)
  {
    int xRight = xs[right];
    if (!mp.count(xRight))
    {
      mp[xRight] = 0;
    }
    mp[xRight]++;

    if ((int)mp.size() > k)
    {
      while (true)
      {
        int xLeft = xs[left];
        mp[xLeft]--;
        left++;
        if (!mp[xLeft])
        {
          mp.erase(xLeft);
          break;
        }
      }
    }

    ans += right - left + 1;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}