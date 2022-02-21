#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<int> vec(n + 1, 0);
  unordered_map<int, int> posMap;
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    vec[i] = x;
    posMap[x] = i;
  }

  posMap[0] = 0;
  int prev = 0;
  int ans = 1;
  for (int i = 1; i <= n; i++)
  {
    if (posMap[i] < prev)
    {
      ans++;
    }

    prev = posMap[i];
  }

  for (int i = 0; i < m; i++)
  {
    int posA, posB;
    cin >> posA >> posB;

    int a = vec[posA];
    int b = vec[posB];

    // a - 1
    if (posMap[a - 1] < posA && posMap[a - 1] >= posB)
    {
      ans++;
    }
    if (posMap[a - 1] > posA && posMap[a - 1] <= posB)
    {
      ans--;
    }
    // a + 1
    if (posMap[a + 1] < posA && posMap[a + 1] >= posB)
    {
      ans--;
    }
    if (posMap[a + 1] > posA && posMap[a + 1] <= posB)
    {
      ans++;
    }
    // b - 1
    if (posMap[b - 1] < posA && posMap[b - 1] > posB)
    {
      ans--;
    }
    if (posMap[b - 1] > posA && posMap[b - 1] < posB)
    {
      ans++;
    }
    // b + 1
    if (posMap[b + 1] < posA && posMap[b + 1] > posB)
    {
      ans++;
    }
    if (posMap[b + 1] > posA && posMap[b + 1] < posB)
    {
      ans--;
    }

    cout << ans << endl;
    
    swap(vec[posA], vec[posB]);
    swap(posMap[a], posMap[b]);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}