#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n, s;
  cin >> n >> s;

  // map[num] = index
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    int target = s - x;
    if (m.count(target))
    {
      cout << i+1 << ' ' << m[target]+1;
      return;
    }

    m[x] = i;
  }

  cout << "IMPOSSIBLE";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}