// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1e6;

void solve()
{
  int n;
  cin >> n;

  vector<int> cnts(N + 1, 0);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnts[x]++;
  }

  for (int i = N; i >= 1; i--)
  {
    int cnt = 0;
    for (int j = i; j < N + 1; j += i)
    {
      cnt += cnts[j];
    }

    if(cnt >= 2){
      cout << i;
      return;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}