#include <bits/stdc++.h>
using namespace std;

// ceil(a / b) = (a + b — 1) / b

// 7, 3 -> ceil(7 - 2) / 3 = 2
// 1, 2 -> 1
// 3, 4, 5 -> 2
// 6, 7, 8 -> 3

// be careful with case 1, 1
void solve()
{
  int n, x;
  cin >> n >> x;
  if(n < 3){
    cout << 1 << endl;
    return;
  }

  int ans = (n - 3) / x + 2;
  cout << ans << endl;
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