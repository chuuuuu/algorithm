#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;

  map<int, int> m;
  vector<int> vec;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
    m[x] = i;
  }

  int prev = -1;
  int ans = 1;
  for (int i = 1; i <= n; i++)
  {
    int cur = m[i];
    if(cur > prev){
      prev = cur;
      continue;
    }

    prev = cur;
    ans++;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}