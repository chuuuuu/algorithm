#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int D, N;
  cin >> D >> N;
  vector<int> pos(N, 0);
  vector<int> speed(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> pos[i] >> speed[i];
  }

  double maxTime = 0;
  for (int i = 0; i < N; i++)
  {
    double time = double(D-pos[i]) / speed[i];
    maxTime = max(maxTime, time);
  }

  double ans = D / maxTime;
  cout << fixed << setprecision(6) << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}