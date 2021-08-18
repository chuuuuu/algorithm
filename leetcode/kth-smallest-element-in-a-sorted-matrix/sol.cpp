#include <bits/stdc++.h>

using namespace std;

/*
// upper_bound and lower_bound explanation:
// given a sorted vector

auto lower = lower_bound(vector.begin(), vector.end(), value)
auto upper = upper_bound(vector.begin(), vector.end(), value)
for(auto it=lower; i!=uppper; i++){
  // every value in the [lower, upper) interval should be value
  assert(*it == value)
}
*/

// to be more concise,
// lower_bound will return the first value which is greater or equal to value
// upper_bound will return the first value which is greater than value

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    auto size = matrix.size();
    auto head = matrix[0][0];
    auto tail = matrix[size - 1][size - 1] + 1;

    while (true)
    {
      if (head + 1 == tail)
      {
        break;
      }

      auto middle = (head + tail) / 2;

      // count: total number of elements in the matrix less than middle
      auto count = 0;
      for (auto i = 0; i < size; i++)
      {
        vector<int> &row = matrix[i];
        count += lower_bound(row.begin(), row.end(), middle) - row.begin();
      }

      // x < middle cannot be the answer
      if (count < k)
      {
        head = middle;
        continue;
      }

      // x >= middle cannot be the answer
      tail = middle;
    }

    return head;
  }
};