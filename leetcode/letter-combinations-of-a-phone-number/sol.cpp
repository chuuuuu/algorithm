#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> letterCombinations(string digits)
  {
    if (!digits.size())
    {
      return {};
    }

    unordered_map<char, vector<char>> map = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    return letterCombinations(digits.size(), digits, map);
  }

  vector<string> letterCombinations(int size, string &digits, unordered_map<char, vector<char>> &map)
  {
    if (size == 0)
    {
      return {""};
    }

    auto combs = letterCombinations(size - 1, digits, map);
    vector<string> ret;
    auto digit = digits[size - 1];
    for (auto comb : combs)
    {
      for (auto c : map[digit])
      {
        ret.push_back(comb + c);
      }
    }

    return ret;
  }
};