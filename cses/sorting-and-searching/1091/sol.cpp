#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n, m;
  cin >> n >> m;

  multiset<int> tickets;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    tickets.insert(t);
  }

  for (int i = 0; i < m; i++)
  {
    int c;
    cin >> c;
    auto it = tickets.upper_bound(c);
    if (it == tickets.begin())
    {
      cout << -1 << endl;
      continue;
    }

    it--;
    cout << *it << endl;
    tickets.erase(it);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}