#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll n;
  cin >> n;
  ll x, s = 0;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> x;
    s += x;
  }

  cout << n * (n + 1) / 2 - s;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}