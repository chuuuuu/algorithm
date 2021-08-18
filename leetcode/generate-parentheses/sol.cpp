#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    return this->generateParenthesis(n, n);
  }

  // given #left '(' and #right ')', return all possible combinations
  vector<string> generateParenthesis(int left, int right)
  {
    if (right == 0)
    {
      return {string(left, '(')};
    }

    vector<string> ret;
    for (auto str : this->generateParenthesis(left, right - 1))
    {
      str.push_back(')');
      ret.push_back(str);
    }

    if (left > right)
    {
      for (auto str : this->generateParenthesis(left - 1, right))
      {
        str.push_back('(');
        ret.push_back(str);
      }
    }

    return ret;
  }
};