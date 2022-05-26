#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int minC = INT_MAX, minM = INT_MAX, minY = INT_MAX, minK = INT_MAX;
  for (int i = 0; i < 3; i++)
  {
    int C, M, Y, K;
    cin >> C >> M >> Y >> K;
    minC = min(minC, C);
    minM = min(minM, M);
    minY = min(minY, Y);
    minK = min(minK, K);
  }

  if (minC + minM + minY + minK < 1000000)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  if (minC >= 1000000)
  {
    cout << "1000000 0 0 0" << endl;
    return;
  }

  if (minC + minM >= 1000000)
  {
    cout << minC << " " << 1000000 - minC << " 0 0" << endl;
    return;
  }

  if (minC + minM + minY >= 1000000)
  {
    cout << minC << " " << minM << " " << 1000000 - minC - minM << " 0" << endl;
    return;
  }

  cout << minC << " " << minM << " " << minY << " " << 1000000 - minC - minM - minY << endl;
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