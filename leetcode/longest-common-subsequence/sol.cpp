#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int size1 = text1.size() + 1;
    int size2 = text2.size() + 1;
    vector<vector<int>> dp(size1, vector(size2, 0));
    for (auto i = 1; i < size1; i++)
    {
      for (auto j = 1; j < size2; j++)
      {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

        if (text1[i - 1] == text2[j - 1])
        {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }

    return dp[size1 - 1][size2 - 1];
  }
};