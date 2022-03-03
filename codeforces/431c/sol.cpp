#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

void solve()
{
  // n, k, d >= 1
  int n, k, d;
  cin >> n >> k >> d;

  // at most k
  vector<int> g(n + 1, 0);
  g[0] = 1;
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j <= min(i, k); j++)
    {
      g[i] += g[i - j];
      g[i] %= mod;
    }
  }

  // at most k, and at least one >= d
  vector<int> f(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j <= min(i, k); j++)
    {
      if (j >= d)
      {
        f[i] += g[i - j];
        f[i] %= mod;
        continue;
      }

      f[i] += f[i - j];
      f[i] %= mod;
    }
  }

  cout << f.back();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}