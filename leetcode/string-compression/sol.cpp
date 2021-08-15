#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    chars.push_back('\0');
    auto prev = chars[0];
    auto count = 0;
    auto write_pos = 0;
    for (auto c1 : chars)
    {
      if (c1 == prev)
      {
        count += 1;
        continue;
      }

      chars[write_pos] = prev;
      write_pos += 1;

      if (count != 1)
      {
        auto count_str = to_string(count);
        for (auto c2 : count_str)
        {
          chars[write_pos] = c2;
          write_pos += 1;
        }
      }

      prev = c1;
      count = 1;
    }

    return write_pos;
  }
};