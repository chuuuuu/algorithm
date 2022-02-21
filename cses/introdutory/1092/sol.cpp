#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  if (n % 4 == 1 || n % 4 == 2)
  {
    cout << "NO";
    return;
  }

  cout << "YES" << endl;
  // n = 8
  // 1 2 7 8
  // 3 4 5 6
  if (n % 4 == 0)
  {
    cout << n / 2 << endl;
    // 1 2
    for (int i = 1; i <= n / 4; i++)
    {
      cout << i << ' ';
    }
    // 7 8
    for (int i = n / 4 * 3 + 1; i <= n; i++)
    {
      cout << i << ' ';
    }
    cout << endl;

    cout << n / 2 << endl;
    // 3 4 5 6
    for (int i = n / 4 + 1; i <= n / 4 * 3; i++)
    {
      cout << i << ' ';
    }
    cout << endl;

    return;
  }

  // n = 7
  // 1 6, 7
  // 2 3 4 5
  // n = 11
  // 1 2 9 10, 11
  // 3 4 5 6 7 8
  cout << n / 2 << endl;
  for (int i = 1; i < (n + 1) / 4; i++)
  {
    cout << i << ' ';
  }
  for (int i = (n + 1) * 3 / 4; i <= n; i++)
  {
    cout << i << ' ';
  }
  cout << endl;

  cout << n / 2 + 1 << endl;
  for (int i = (n + 1) / 4; i < (n + 1) * 3 / 4; i++)
  {
    cout << i << ' ';
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}