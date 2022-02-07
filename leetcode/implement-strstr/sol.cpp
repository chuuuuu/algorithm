// KMP algorithm guarantee O(N+M) in worst case
// however, it is tricky and you dont need to memorize it
// rabin karp gives an algorithm O(N+M) on average

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if (haystack.size() < needle.size())
    {
      return -1;
    }

    int mod = (1 << 16) - 1;
    int base = 1;
    for (int i = 0; i < int(needle.size()) - 1; i++)
    {
      base *= 26;
      base %= mod;
    }
    int needleHash = getHash(needle, mod);
    int pos = 0;
    int haystackHash = getHash(haystack.substr(pos, needle.size()), mod);
    while (true)
    {
      if (needleHash == haystackHash && needle == haystack.substr(pos, needle.size()))
      {
        return pos;
      }

      if (pos + needle.size() >= haystack.size())
      {
        break;
      }

      haystackHash -= (haystack[pos] - 'a') * base;
      haystackHash *= 26;
      haystackHash += haystack[pos + needle.size()] - 'a';
      // due to the negtive mod problem
      haystackHash = (haystackHash % mod + mod) % mod;
      pos++;
    }

    return -1;
  }

  int getHash(string str, int mod)
  {
    if (!str.size())
    {
      return 0;
    }

    int ret = str[0] - 'a';
    for (int i = 1; i < str.size(); i++)
    {
      ret *= 26;
      ret += str[i] - 'a';
      ret %= mod;
    }

    return ret;
  }
};