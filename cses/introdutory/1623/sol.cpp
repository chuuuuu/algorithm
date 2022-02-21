#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 5 5 5 7 8
void solve()
{
  int n;
  cin >> n;
  vector<ll> vec(n, 0);
  ll s = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
    s += vec[i];
  }

  ll left, right;
  ll ans = 2e10;
  for (int i = 0; i < (1 << n); i++)
  {
    left = 0;
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        left += vec[j];
      }
    }

    right = s - left;
    ans = min(ans, abs(left-right));
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}