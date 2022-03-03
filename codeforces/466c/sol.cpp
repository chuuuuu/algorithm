#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  // *1* 2 3 0 *3*
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  // *0, 1*, 3, 6, 6, *9*
  vector<ll> preSum(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    preSum[i] = preSum[i - 1] + vec[i - 1];
  }

  if (preSum.back() % 3 != 0)
  {
    cout << 0;
    return;
  }

  ll target = preSum.back() / 3;
  int countTarget = 0;
  ll ans = 0;
  for (int i = 1; i < n; i++)
  {
    if (preSum[i] == 2 * target)
    {
      ans += countTarget;
    }

    if (preSum[i] == target)
    {
      countTarget++;
    }
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}