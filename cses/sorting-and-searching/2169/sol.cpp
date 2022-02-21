#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
 
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct Interval
{
  int left;
  int right;
  int index;
};
 
void solve()
{
  int n;
  cin >> n;
 
  vector<Interval> intervals;
  for(int i=0; i<n; i++){
    int left, right;
    cin >> left >> right;
    intervals.push_back({left, right, i});
  }
 
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
 
  sort(intervals.begin(), intervals.end(), cmp);
  
  vector<int> ans1(n, 0);
  ordered_multiset<int> om1;
  for(int i=n-1; i>=0; i--){
    auto interval = intervals[i];
    ans1[interval.index] = om1.order_of_key(interval.right+1);
    om1.insert(interval.right);
  }
 
  for(int i=0; i<n; i++){
    cout << ans1[i] << ' ';
  }
  cout << endl;
 
 
  vector<int> ans2(n, 0);
  ordered_multiset<int> om2;
  for(int i=0; i<n; i++){
    auto interval = intervals[i];
    ans2[interval.index] = om2.size() - om2.order_of_key(interval.right);
    om2.insert(interval.right);
  }
 
  for(int i=0; i<n; i++){
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