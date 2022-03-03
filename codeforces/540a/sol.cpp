#include <bits/stdc++.h>
using namespace std;

// 0, 1, 2, 3, 4, 5
// 0, 9, 8, 7, 6, 5
void solve()
{
  int n;
  cin >> n;

  string start;
  string target;
  cin >> start >> target;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += min(10 - abs(target[i] - start[i]), abs(target[i] - start[i]));
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}