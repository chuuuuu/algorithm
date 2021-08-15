#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end(), [](vector<int> &interval1, vector<int> &interval2)
         { return interval1[0] < interval2[0]; });

    vector<vector<int>> ret;
    auto head = intervals[0][0];
    auto tail = intervals[0][1];
    for (auto interval : intervals)
    {
      if (interval[0] <= tail)
      {
        tail = max(tail, interval[1]);
        continue;
      }

      ret.push_back({head, tail});
      head = interval[0];
      tail = interval[1];
    }

    ret.push_back({head, tail});

    return ret;
  }
};