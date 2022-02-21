#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int a, b;
  cin >> a >> b;
  if ((a + b) % 3 != 0)
  {
    cout << "NO" << endl;
    return;
  }

  int x = (a + b) / 3;
  if(a - x < 0 || b - x < 0){
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
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