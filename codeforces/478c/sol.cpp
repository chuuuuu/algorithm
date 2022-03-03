#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll r, g, b;
  cin >> r >> g >> b;

  ll big = max(r, max(g, b));
  ll remain = r + g + b - big;
  if (big > 2 * remain)
  {
    cout << remain;
    return;
  }

  cout << (big + remain) / 3;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}