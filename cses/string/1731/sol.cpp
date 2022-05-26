// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  string target;
  cin >> target;

  int k;
  cin >> k;

  vector<string> words(k);
  for (string &word : words)
  {
    cin >> word;
  }

  int n = target.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  int mod = 1e9+7;
  for (int i = 1; i < n + 1; i++)
  {
    for (string &word : words)
    {
      int nWord = word.size();
      if (nWord <= i && word == target.substr(i - nWord, nWord))
      {
        dp[i] += dp[i - nWord];
        dp[i] %= mod;
      }
    }
  }

  cout << dp[n];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}