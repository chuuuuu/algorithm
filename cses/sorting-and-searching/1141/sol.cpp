#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  int head = 0;
  set<int> s;
  int ans = 0;
  for (int tail = 0; tail < n; tail++)
  {
    int num = vec[tail];
    if (s.count(num))
    {
      while (true)
      {
        if (vec[head] == num)
        {
          head++;
          break;
        }
        s.erase(vec[head]);
        head++;
      }
    }

    s.insert(num);
    ans = max(tail - head + 1, ans);
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}