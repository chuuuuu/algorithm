// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int f(int n, int k)
{
  if (n == 1)
  {
    return 1;
  }
  
  // odd
  if (n & 1)
  {
    if (k <= (n + 1) / 2)
    {
      return 2 * k % n;
    }
    else
    {
      return 2 * f(n - (n + 1) / 2, k - (n + 1) / 2) + 1;
    }
  }
  // even
  else
  {
    if (k <= n / 2)
    {
      return 2 * k;
    }
    else
    {
      return 2 * f(n - n / 2, k - n / 2) - 1;
    }
  }
}

void solve()
{
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int n, k;
    cin >> n >> k;

    cout << f(n, k) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}