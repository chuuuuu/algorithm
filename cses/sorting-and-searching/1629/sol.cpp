#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  // first: end, second: start
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++)
  {
    int start, end;
    cin >> start >> end;
    vec.push_back({end, start});
  }

  sort(vec.begin(), vec.end());
  int prevEnd = vec[0].first;
  int ans = 1;
  for (int i = 1; i < n; i++)
  {
    if(vec[i].second < prevEnd){
      continue;
    }

    prevEnd = vec[i].first;
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