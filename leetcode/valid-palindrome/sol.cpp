#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    string newStr;
    for (auto c : s)
    {
      if (isNumber(c) || isLower(c))
      {
        newStr.push_back(c);
        continue;
      }

      if (isUpper(c))
      {
        newStr.push_back('a' + (c - 'A'));
        continue;
      }
    }

    int size = newStr.size();
    for (int i = 0; i < size; i++)
    {
      if (newStr[i] != newStr[size - 1 - i])
      {
        return false;
      }
    }

    return true;
  }

  bool isNumber(char c)
  {
    if (c - '0' < 10 && c - '0' >= 0)
    {
      return true;
    }

    return false;
  }

  bool isUpper(char c)
  {
    if (c - 'A' < 26 && c - 'A' >= 0)
    {
      return true;
    }

    return false;
  }

  bool isLower(char c)
  {
    if (c - 'a' < 26 && c - 'a' >= 0)
    {
      return true;
    }

    return false;
  }
};