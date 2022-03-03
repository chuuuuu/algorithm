#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  int ans = 0;
  int prev = vec[0];
  for (int i = 1; i < n; i++)
  {
    int big = max(prev, vec[i]);
    int small = min(prev, vec[i]);
    if (2 * small < big)
    {
      double ratio = big / double(small);
      ans += ceil(log2(ratio)) - 1;
    }

    prev = vec[i];
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