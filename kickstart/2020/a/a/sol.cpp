#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, b;
  cin >> n >> b;

  vector<int> a(n, 0);
  for (auto i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto tot = 0;
  auto ans = 0;
  for (auto price : a)
  {
    tot += price;
    if (tot > b)
    {
      break;
    }

    ans += 1;
  }

  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}