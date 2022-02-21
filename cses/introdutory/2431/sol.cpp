#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  ll k;
  cin >> k;
  ll totCount = 0;
  ll count = 9;
  ll digit = 1;
  ll base = 1;
  while (true)
  {
    ll nextTotCount = totCount + count * digit;
    if (nextTotCount >= k)
    {
      break;
    }
    totCount = nextTotCount;
    base *= 10;
    count *= 10;
    digit += 1;
  }

  ll x = (k - totCount - 1) / digit;
  ll y = (k - totCount - 1) % digit;
  cout << to_string(base + x)[y] << endl;
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