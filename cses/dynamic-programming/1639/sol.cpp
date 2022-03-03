// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  string word1, word2;
  cin >> word1 >> word2;

  int n1 = word1.size();
  int n2 = word2.size();

  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
  for (int i = 0; i < n1 + 1; i++)
  {
    dp[i][0] = i;
  }
  for (int j = 0; j < n2 + 1; j++)
  {
    dp[0][j] = j;
  }

  for (int i = 1; i < n1 + 1; i++)
  {
    for (int j = 1; j < n2 + 1; j++)
    {
      if (word1[i - 1] == word2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
      }
    }
  }

  cout << dp[n1][n2];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}