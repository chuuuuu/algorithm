#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    auto cmp = [](vector<int> &point1, vector<int> &point2)
    {
      return point1[0] < point2[0];
    };

    sort(points.begin(), points.end(), cmp);

    auto ret = 0;
    auto head = points[0][0];
    auto tail = points[0][1];
    for (auto i = 1; i < points.size(); i++)
    {
      auto &point = points[i];
      if (point[0] <= tail)
      {
        head = point[0];
        tail = min(point[1], tail);
        continue;
      }

      ret += 1;
      head = point[0];
      tail = point[1];
    }

    ret += 1;
    return ret;
  }
};