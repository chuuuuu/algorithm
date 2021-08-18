#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> ms(n, 0);
  for (auto i = 0; i < n; i++)
  {
    cin >> ms[i];
  }

  vector<int> diffs(n, 0);
  for (auto i = 1; i < n; i++)
  {
    diffs[i] = ms[i] - ms[i - 1];
  }

  int head = 0;
  int tail = 1e9;
  while (true)
  {
    if (head + 1 == tail)
    {
      break;
    }

    int middle = (head + tail) / 2;
    int tot = 0;
    for (auto diff : diffs)
    {
      tot += diff / middle;
      if (diff && ((diff % middle) == 0))
      {
        tot -= 1;
      }
    }

    if (tot <= k)
    {
      tail = middle;
      continue;
    }

    head = middle;
  }

  auto ans = tail;
  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}