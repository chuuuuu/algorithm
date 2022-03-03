#include <bits/stdc++.h>
using namespace std;

// 2, 2, 1
// a = 2, b = 1, c = 1

// a >= b >= c
// x = a, y = a, z = b
// x = y >= z

// a >= c >= b
// x = a, y = a, z = c
// x = y >= z

// b >= a >= c
// x = b, y = a, z = b
// x = z >= y

// b >= c >= a
// x = b, y = c, z = b
// x = z >= y

// c >= a >= b
// x = a, y = c, z = c
// y = z >= x

// c >= b >= a
// x = b, y = c, z = c
// y = z >= x

void solve()
{
  int x, y, z;
  cin >> x >> y >> z;
  int a = max(max(x, y), z);
  int b = min(min(x, y), z);
  if ((x == a) + (y == a) + (z == a) == 1)
  {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  cout << a << " " << b << " " << b << endl;
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