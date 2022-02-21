#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll n;
  cin >> n;
  cout << n << ' ';
  while (true)
  {
    if (n == 1)
    {
      break;
    }

    if ((n & 1) == 0)
    {
      n = n / 2;
      cout << n << ' ';
      continue;
    }

    // else
    n = 3 * n + 1;
    cout << n << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}