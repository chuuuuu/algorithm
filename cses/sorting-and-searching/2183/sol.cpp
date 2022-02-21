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

  sort(vec.begin(), vec.end());

  // we can create [1 ... s]
  ll s = 0;
  for (int i = 0; i < n; i++)
  {
    if (s + 1 < vec[i])
    {
      break;
    }

    s += vec[i];
  }

  cout << s + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}