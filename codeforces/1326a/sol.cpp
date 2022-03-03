#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  if (n == 1)
  {
    cout << -1 << endl;
    return;
  }

  cout << 2;
  for (int i = 1; i < n; i++)
  {
    cout << 3;
  }
  cout << endl;
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