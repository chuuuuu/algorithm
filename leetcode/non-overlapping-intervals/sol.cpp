#include <bits/stdc++.h>
using namespace std;

// 1--4
// -2--5
// --34
// ---4-6

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    auto cmp = [](vector<int> &interval1, vector<int> &interval2)
    {
      return interval1[0] < interval2[0];
    };

    sort(intervals.begin(), intervals.end(), cmp);

    int ret = 0;
    int head = intervals[0][0];
    int tail = intervals[0][1];
    for (auto i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] >= tail)
      {
        head = intervals[i][0];
        tail = intervals[i][1];
        continue;
      }

      if (tail > intervals[i][1])
      {
        head = intervals[i][0];
        tail = intervals[i][1];
        ret += 1;
        continue;
      }

      ret += 1;
    }

    return ret;
  }
};