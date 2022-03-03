#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string word;
  cin >> word;
  int stackSize = 0;
  for (char c : word)
  {
    if (c == 'B' && stackSize)
    {
      stackSize--;
      continue;
    }
    stackSize++;
  }

  cout << stackSize << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
}