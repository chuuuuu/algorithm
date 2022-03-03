#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int k, r;
  cin >> k >> r;
  for (int i = 1; i < 11; i++)
  {
    if ((k * i) % 10 == 0)
    {
      cout << i << endl;
      return;
    }

    if ((k * i - r) % 10 == 0)
    {
      cout << i << endl;
      return;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}