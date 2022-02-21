#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int x, n;
  cin >> x >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  set<int> s = {0, x};
  multiset<int> ms = {x};
  for (int i = 0; i < n; i++)
  {
    int pos = vec[i];

    auto it = s.upper_bound(pos);
    int posBigger = *it;
    it--;
    int posSmaller = *it;
    s.insert(pos);

    ms.erase(ms.find(posBigger-posSmaller));
    ms.insert(posBigger - pos);
    ms.insert(pos - posSmaller);
    
    auto itBiggest = ms.end();
    itBiggest--;
    cout << *itBiggest << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}