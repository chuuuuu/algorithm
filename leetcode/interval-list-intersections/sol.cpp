#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
  {
    auto firstIndex = 0;
    auto secondIndex = 0;
    vector<vector<int>> ret;
    while (true)
    {
      if(firstIndex == firstList.size() || secondIndex == secondList.size()){
        break;
      }
      auto &firstInterval = firstList[firstIndex];
      auto &secondInterval = secondList[secondIndex];
      auto firstHead = firstInterval[0];
      auto firstTail = firstInterval[1];
      auto secondHead = secondInterval[0];
      auto secondTail = secondInterval[1];

      auto maxHead = max(firstHead, secondHead);
      auto minTail = min(firstTail, secondTail);
      if (maxHead <= minTail)
      {
        ret.push_back({maxHead, minTail});
      }

      if (firstTail > secondTail)
      {
        secondIndex += 1;
        continue;
      }

      firstIndex += 1;
    }

    return ret;
  }
};
