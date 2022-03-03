#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N = 1e5;
int mod = 1e9 + 7;
int k;
vector<int> dpPreSum(N + 2, 0);

void build()
{
  vector<int> dp(N + 1, 1);
  for (int i = k; i < N + 1; i++)
  {
    dp[i] = dp[i - 1] + dp[i - k];
    dp[i] %= mod;
  }

  for (int i = 1; i < N + 2; i++)
  {
    dpPreSum[i] = dpPreSum[i - 1] + dp[i - 1];
    dpPreSum[i] %= mod;
  }
}

void solve()
{
  int a, b;
  cin >> a >> b;

  cout << (dpPreSum[b + 1] - dpPreSum[a] + mod) % mod << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t >> k;
  build();

  for (int i = 0; i < t; i++)
  {
    solve();
  }
}