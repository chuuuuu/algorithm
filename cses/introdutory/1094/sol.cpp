#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;

  int prev = 0;
  int x;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if (x < prev)
    {
      ans += prev - x;
      continue;
    }

    prev = x;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}