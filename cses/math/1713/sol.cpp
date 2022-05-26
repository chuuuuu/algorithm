// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1e6;
vector<int> cnts(N + 1, 0);

void build()
{
  for (int i = 1; i < N + 1; i++)
  {
    for (int j = i; j < N + 1; j += i)
    {
      cnts[j]++;
    }
  }
}

void solve()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cout << cnts[x] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  build();
  solve();
}