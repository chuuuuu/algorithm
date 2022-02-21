#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n, x;
  cin >> n >> x;

  vector<int> weights(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
  }

  sort(weights.begin(), weights.end());
  int pos = 0;
  int ans = 0;
  for (int i = weights.size() - 1; i >= 0; i--)
  {
    if (i < pos)
    {
      break;
    }

    int w1 = weights[i];
    int w2 = weights[pos];
    if (w1 + w2 <= x)
    {
      pos++;
    }

    ans++;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}