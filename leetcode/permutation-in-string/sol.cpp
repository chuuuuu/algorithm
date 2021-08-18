#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    vector<int> goal(26, 0);
    for (auto c : s1)
    {
      goal[c - 'a'] += 1;
    }

    int head = 0;
    vector<int> current(26, 0);
    for (auto i = 0; i < s2.size(); i++)
    {
      int index = s2[i] - 'a';
      if (!goal[index])
      {
        head = i + 1;
        for (auto j = 0; j < 26; j++)
        {
          current[j] = 0;
        }
        continue;
      }

      if (current[index] < goal[index])
      {
        current[index] += 1;
        if (i - head + 1 == s1.size())
        {
          return true;
        }

        continue;
      }

      while (true)
      {
        int headIndex = s2[head] - 'a';
        current[headIndex] -= 1;
        head += 1;
        if (headIndex == index)
        {
          current[index] += 1;
          break;
        }
      }
    }

    return false;
  }
};