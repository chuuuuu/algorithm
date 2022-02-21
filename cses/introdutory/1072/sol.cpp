#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// If two knight attack each other then they will be in 2*3 rectangle or 3*2 rectangle.
void solve()
{
  ll n;
  cin >> n;
  for (ll i = 1; i <= n; i++)
  {
    cout << i * i * (i * i - 1) / 2 - 2 * 2 * (i - 1) * (i - 2) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}