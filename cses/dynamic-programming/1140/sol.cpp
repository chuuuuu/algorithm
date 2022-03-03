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
  int price;
};

void solve()
{
  int n;
  cin >> n;

  vector<Interval> intervals = {{0, 0, 0}};
  for (int i = 0; i < n; i++)
  {
    int left, right, price;
    cin >> left >> right >> price;
    intervals.push_back({left, right, price});
  }

  auto cmp = [](Interval i1, Interval i2)
  {
    return i1.right < i2.right;
  };

  sort(intervals.begin(), intervals.end(), cmp);

  vector<ll> dp(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    auto [left, right, price] = intervals[i];
    auto it = lower_bound(intervals.begin(), intervals.end(), (Interval){0, left, 0}, cmp);
    int index = prev(it) - intervals.begin();
    dp[i] = max(dp[i - 1], dp[index] + price);
  }

  cout << dp.back();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}