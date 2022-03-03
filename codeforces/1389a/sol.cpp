#include <bits/stdc++.h>
using namespace std;

// given l, r
// find x, y
// s.t. l <= x < y <= r and l <= LCM(x, y) <= r
// lcm of x is possible to be x, 2x, ...
// hence the smallest possible become l and 2l
void solve()
{
  int l, r;
  cin >> l >> r;
  if (l * 2 > r)
  {
    cout << "-1 -1" << endl;
    return;
  }
  cout << l << " " << 2*l << endl; 
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