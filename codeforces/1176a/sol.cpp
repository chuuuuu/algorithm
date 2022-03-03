#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll n;
  cin >> n;

  int ans = 0;
  while (true)
  {
    if (n == 1)
    {
      break;
    }

    if (n % 5 == 0)
    {
      n *= 4;
      n /= 5;
      ans++;
      continue;
    }
    if (n % 3 == 0)
    {
      n *= 2;
      n /= 3;
      ans++;
      continue;
    }
    if (n % 2 == 0)
    {
      n /= 2;
      ans++;
      continue;
    }
    cout << -1 << endl;
    return;
  }

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