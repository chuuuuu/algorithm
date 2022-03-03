// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll getDigit(string &number, ll k)
{
  ll n = number.size();
  return number[n - k] - '0';
}

ll getCount(ll number)
{
  if (number < 0)
  {
    return 0;
  }

  string word = to_string(number);
  ll n = word.size();

  vector<ll> notLeadingZero(n + 1, 0);
  vector<ll> leadingZero(n + 1, 0);
  notLeadingZero[1] = 9;
  leadingZero[1] = 1;
  for (ll i = 2; i < n + 1; i++)
  {
    notLeadingZero[i] = notLeadingZero[i - 1] * 9;
    leadingZero[i] = leadingZero[i - 1] + notLeadingZero[i - 1];
  }

  vector<vector<ll>> tight(n + 1, vector<ll>(10, 0));
  for (int d = 0; d <= getDigit(word, 1); d++)
  {
    tight[1][d] = 1;
  }

  for (ll i = 2; i < n + 1; i++)
  {
    ll digit = getDigit(word, i);
    for (ll d = 0; d < digit; d++)
    {
      tight[i][d] = notLeadingZero[i - 1];
    }

    for (ll d = 0; d < 10; d++)
    {
      if (d == digit)
      {
        continue;
      }

      tight[i][digit] += tight[i - 1][d];
    }
  }

  ll ret = leadingZero[n];
  for (ll d = 1; d < 10; d++)
  {
    ret += tight[n][d];
  }
  return ret;
}

void solve()
{
  ll a, b;
  cin >> a >> b;
  cout << getCount(b) - getCount(a - 1);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}