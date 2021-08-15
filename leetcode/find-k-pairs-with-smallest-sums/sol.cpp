#include <bits/stdc++.h>

using namespace std;

struct Pair
{
  int idx1;
  int idx2;
};

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    auto getSum = [&nums1, &nums2](Pair &pair)
    {
      auto [idx1, idx2] = pair;
      return nums1[idx1] + nums2[idx2];
    };

    auto cmp = [&getSum](Pair &pair1, Pair &pair2)
    { return getSum(pair1) > getSum(pair2); };

    priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp);

    for (auto i = 0; i < nums1.size(); i++)
    {
      pq.push({i, 0});
    }

    vector<vector<int>> ret;
    while (true)
    {
      if (ret.size() == k)
      {
        break;
      }

      if (pq.empty())
      {
        break;
      }

      auto [idx1, idx2] = pq.top();
      pq.pop();

      if (idx2 + 1 < nums2.size())
      {
        pq.push({idx1, idx2 + 1});
      }

      ret.push_back({nums1[idx1], nums2[idx2]});
    }

    return ret;
  }
};