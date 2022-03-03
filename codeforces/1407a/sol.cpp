#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  int count0 = 0;
  int count1 = 0;
  for (int i = 0; i < n; i++)
  {
    if (vec[i] == 0)
    {
      count0++;
      continue;
    }

    count1++;
  }

  if (count1 > count0)
  {
    int ans;
    ans = count1 / 2 * 2;
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
      cout << "1 ";
    }
    cout << endl;
    return;
  }

  cout << count0 << endl;
  for (int i = 0; i < count0; i++)
  {
    cout << "0 ";
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