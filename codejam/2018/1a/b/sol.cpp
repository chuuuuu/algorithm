#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(ll time, ll R, ll B, ll C, vector<ll> &Ms, vector<ll> &Ss, vector<ll> &Ps)
{
  vector<ll> maxBits(C, 0);
  for (ll i = 0; i < C; i++)
  {
    maxBits[i] = (time - Ps[i] > 0) ? min(Ms[i], (time - Ps[i]) / Ss[i]) : 0;
  }

  sort(maxBits.begin(), maxBits.end());
  reverse(maxBits.begin(), maxBits.end());
  ll totBit = 0;
  for (ll i = 0; i < R; i++)
  {
    totBit += maxBits[i];
  }

  return totBit >= B;
}

void solve()
{
  ll R, B, C;
  cin >> R >> B >> C;
  vector<ll> Ms(C, 0);
  vector<ll> Ss(C, 0);
  vector<ll> Ps(C, 0);
  for (ll i = 0; i < C; i++)
  {
    cin >> Ms[i] >> Ss[i] >> Ps[i];
  }

  ll maxTime = 0;
  for (ll i = 0; i < C; i++)
  {
    maxTime = max(maxTime, Ms[i] * Ss[i] + Ps[i]);
  }

  // inclusive
  ll head = 0;
  ll tail = maxTime;
  while (true)
  {
    if (head == tail)
    {
      break;
    }

    ll mid = (head + tail) / 2;
    if (isPossible(mid, R, B, C, Ms, Ss, Ps))
    {
      tail = mid;
      continue;
    }

    head = mid + 1;
  }

  cout << head << "\n";
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