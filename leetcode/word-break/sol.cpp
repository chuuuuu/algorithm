#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool wordBreak(string &s, vector<string> &wordDict)
  {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (auto i = 1; i < dp.size(); i++)
    {
      for (auto word : wordDict)
      {
        auto size = word.size();
        if (size > i)
        {
          continue;
        }

        if(s.substr(i-size, size) != word){
          continue;
        }

        dp[i] = dp[i - size];
        if (dp[i])
        {
          break;
        }
      }
    }

    return dp.back();
  }
};