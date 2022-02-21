#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll y, x;
  cin >> y >> x;

  if (y > x)
  {
    if (y % 2 == 0)
    {
      cout << y * y + 1 - x << endl;
      return;
    }
    // y % 2 == 1
    y = y - 1;
    cout << y * y + x << endl;
    return;
  }

  // x > y
  if (x % 2 == 1)
  {
    cout << x * x + 1 - y << endl;
    return;
  }

  // x % 2 == 0
  x = x - 1;
  cout << x * x + y << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
}