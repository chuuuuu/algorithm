#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    int arrival, leaving;
    cin >> arrival >> leaving;
    m[arrival] = 1;
    m[leaving] = -1;
  }

  int ans = 0;
  int s = 0;
  for (auto [key, val] : m)
  {
    s += val;
    ans = max(ans, s);
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}