// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval
{
  int left;
  int right;
  int index;
};

auto cmp = [](Interval &i1, Interval &i2)
{
  if (i1.left < i2.left)
  {
    return true;
  }

  if (i1.left == i2.left && i1.right > i2.right)
  {
    return true;
  }

  return false;
};

void solve()
{
  int n;
  cin >> n;
  vector<Interval> intervals;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    intervals.push_back({x, y, i});
  }

  sort(intervals.begin(), intervals.end(), cmp);

  // mp1[end] = interval;
  map<int, Interval> mp1;
  // ans1[i] == true: i contains some other range
  vector<bool> ans1(n, false);
  for (int i = 0; i < n; i++)
  {
    auto interval = intervals[i];
    int right = interval.right;
    auto it = mp1.lower_bound(right);
    while (true)
    {
      if (it == mp1.end())
      {
        break;
      }

      auto goodInterval = it->second;
      if (goodInterval.left == interval.left && goodInterval.right == interval.right)
      {
        ans1[interval.index] = true;
      }
      ans1[goodInterval.index] = true;
      auto nextIt = next(it);
      mp1.erase(it);
      it = nextIt;
    }

    mp1.insert({interval.right, interval});
  }

  // map[end] = interval;
  map<int, Interval> mp2;
  // ans2[i] == true: i is contained by some other range
  vector<bool> ans2(n, false);
  for (int i = 0; i < n; i++)
  {
    auto interval = intervals[i];
    int right = intervals[i].right;
    auto it = mp2.lower_bound(right);
    if (it != mp2.end())
    {
      auto goodInterval = it->second;
      if (goodInterval.left == interval.left && goodInterval.right == interval.right)
      {
        ans2[goodInterval.index] = true;
      }
      ans2[interval.index] = true;
    }

    mp2.insert({interval.right, interval});
  }

  for (int i = 0; i < n; i++)
  {
    cout << ans1[i] << ' ';
  }
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    cout << ans2[i] << ' ';
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}