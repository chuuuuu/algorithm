#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;

  vector<int> ps;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    ps.push_back(x);
  }

  sort(ps.begin(), ps.end());

  int target = ps[n / 2];
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += abs(ps[i] - target);
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}