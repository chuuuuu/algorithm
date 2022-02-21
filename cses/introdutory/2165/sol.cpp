#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// move n disks from a to b
void f(int n, int a, int b)
{
  if (n == 0)
  {
    return;
  }

  int c = 3 - a - b;
  f(n - 1, a, c);
  cout << a + 1 << ' ' << b + 1 << endl;
  f(n - 1, c, b);
}

void solve()
{
  int n;
  cin >> n;
  cout << (1 << n) - 1 << endl;
  f(n, 0, 2);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}