#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;

  // 1 2 3 4
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // 3 1 2 4
  vector<int> b(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  // 2 -1 -1 0
  vector<int> diff(n, 0);
  for (int i = 0; i < n; i++)
  {
    diff[i] = b[i] - a[i];
  }

  int s = 0;
  for (int i = 0; i < n; i++)
  {
    s += diff[i];
  }
  if (s != 0)
  {
    cout << -1 << endl;
    return;
  }

  // need to be decreased
  // first is number, second is count
  queue<pair<int, int>> iCandidate;
  // need to be increased
  queue<pair<int, int>> jCandidate;
  int operationCount = 0;
  for (int i = 0; i < n; i++)
  {
    if (diff[i] > 0)
    {
      operationCount += diff[i];
      jCandidate.push({i, diff[i]});
      continue;
    }
    if (diff[i] < 0)
    {
      iCandidate.push({i, -diff[i]});
    }
  }

  cout << operationCount << endl;
  for (int k = 0; k < operationCount; k++)
  {
    auto [i, iCount] = iCandidate.front();
    iCandidate.pop();
    iCount--;
    if (iCount)
    {
      iCandidate.push({i, iCount});
    }

    auto [j, jCount] = jCandidate.front();
    jCandidate.pop();
    jCount--;
    if (jCount)
    {
      jCandidate.push({j, jCount});
    }
    
    cout << i+1 << ' ' << j+1 << endl;
  }
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