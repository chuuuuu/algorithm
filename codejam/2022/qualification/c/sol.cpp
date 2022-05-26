#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int N;
  cin >> N;
  vector<int> Ss(N);
  for (int &S : Ss)
  {
    cin >> S;
  }

  sort(Ss.begin(), Ss.end());
  int ans = 0;
  for (int S : Ss)
  {
    if (S > ans)
    {
      ans++;
    }
  }

  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}