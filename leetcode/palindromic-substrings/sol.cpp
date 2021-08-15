// Manacher's Algorithm
// https://havincy.github.io/blog/post/ManacherAlgorithm/
// http://manacher-viz.s3-website-us-east-1.amazonaws.com/#/
// https://www.zhihu.com/question/30226229

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int countSubstrings(string s)
  {
    // aaaaabbaaa
    // ^#a#a#a#a#a#b#b#a#a#a#$
    string sModified = "^#";
    for (auto c : s)
    {
      sModified.push_back(c);
      sModified.push_back('#');
    }
    sModified.push_back('$');

    vector<int> records(sModified.size(), 0);
    auto center = 1;
    auto head = 1;
    auto tail = 1;
    for (auto i = 1; i < sModified.size() - 1; i++)
    {
      auto dx = records[center - (i - center)];
      if (dx + i > tail)
      {
        dx = tail - i;
      }

      while (true)
      {
        auto dxNew = dx + 1;
        if (sModified[i - dxNew] != sModified[i + dxNew])
        {
          if (i + dx > tail)
          {
            center = i;
            head = i - dx;
            tail = i + dx;
          }
          records[i] = dx;
          break;
        }

        dx = dxNew;
      }
    }

    auto ret = 0;
    for (auto record : records)
    {
      ret += (record + 1) / 2;
    }

    return ret;
  }
};

// aaa
// ^#a#a#a#$
// 1 + 2 + 3 + 2 + 1