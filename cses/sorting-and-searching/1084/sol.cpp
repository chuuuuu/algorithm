#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> as(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> as[i];
  }

  vector<int> bs(m, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> bs[i];
  }

  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  int posA = 0;
  int posB = 0;
  int ans = 0;
  while (true)
  {
    if (posA == as.size() || posB == bs.size())
    {
      break;
    }

    if (abs(as[posA] - bs[posB]) <= k)
    {
      ans++;
      posA++;
      posB++;
      continue;
    }

    if (as[posA] < bs[posB])
    {
      posA++;
      continue;
    }

    posB++;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}