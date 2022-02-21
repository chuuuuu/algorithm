#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;

  int num;
  set<int> numSet;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    numSet.insert(num);
  }

  cout << numSet.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}