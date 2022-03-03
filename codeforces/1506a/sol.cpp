#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// x = n * (posx - 1) + posy
// posx = (x - posy) / n + 1
// posy = x % n
void solve()
{
  ll n, m, x;
  cin >> n >> m >> x;
  ll posy = (x % n) == 0 ? n : x % n;
  ll posx = (x - posy) / n + 1;
  cout << (posy - 1) * m + posx << endl;
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
