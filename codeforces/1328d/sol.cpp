#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  // every num in vec is the same
  int num = vec[0];
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (vec[i] == num)
    {
      count++;
    }
  }

  if (count == n)
  {
    cout << 1 << endl;
    for (int i = 0; i < n; i++)
    {
      cout << 1 << ' ';
    }
    cout << endl;
    return;
  }

  // vec.size is even
  if (n % 2 == 0)
  {
    cout << 2 << endl;
    for (int i = 0; i < n; i++)
    {
      cout << i % 2 + 1 << ' ';
    }
    cout << endl;
    return;
  }

  // vec.size is odd, find the pos s.t. pos and pos-1 have the same type
  int pos = -1;
  int prev = vec.back();
  for (int i = 0; i < n; i++)
  {
    if (vec[i] == prev)
    {
      pos = i;
      break;
    }

    prev = vec[i];
  }

  // every neibouring figure have different type
  if (pos == -1)
  {
    cout << 3 << endl;
    for (int i = 0; i < n - 1; i++)
    {
      cout << i % 2 + 1 << ' ';
    }
    cout << 3 << endl;
    return;
  }

  prev = 1;
  cout << 2 << endl;
  for (int i = 0; i < n; i++)
  {
    if (i == pos)
    {
      cout << prev + 1 << ' ';
      continue;
    }

    int cur = prev ^ 1;
    cout << cur + 1 << ' ';
    prev = cur;
  }
  cout << endl;
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