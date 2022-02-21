#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<int>::iterator getNext(set<int>::iterator it, set<int> &s)
{
  auto nextit = next(it);
  return (nextit == s.end()) ? s.begin() : nextit;
}

void solve()
{
  int n;
  cin >> n;

  set<int> s;
  for (int i = 1; i <= n; i++)
  {
    s.insert(i);
  }

  auto it = getNext(s.begin(), s);
  while (true)
  {
    if (s.size() == 1)
    {
      cout << *(s.begin());
      break;
    }

    int val = *it;
    cout << val << ' ';
    
    auto nextIt = getNext(it, s);
    s.erase(it);
    it = getNext(nextIt, s);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}