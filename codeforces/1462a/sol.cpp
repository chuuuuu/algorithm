#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  deque<int> dq;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    dq.push_back(a);
  }

  bool isFront = true;
  while (true)
  {
    if (dq.empty())
    {
      break;
    }

    if (isFront)
    {
      int a = dq.front();
      dq.pop_front();
      cout << a << ' ';
      isFront = false;
      continue;
    }

    int a = dq.back();
    dq.pop_back();
    cout << a << ' ';
    isFront = true;
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