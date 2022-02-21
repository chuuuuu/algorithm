#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  multiset<int> s;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    auto it = s.upper_bound(x);
    if (it == s.end())
    {
      s.insert(x);
      continue;
    }

    s.erase(it);
    s.insert(x);
  }

  cout << s.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}