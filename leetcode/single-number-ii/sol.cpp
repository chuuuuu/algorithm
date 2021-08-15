#include <bits/stdc++.h>

using namespace std;

// we want to find a operator @ such that
// 1 @ 1 @ 1 = 0
// 1 @ 0 = 1

// there are 3 states we need to store, hence we need 2 bits
// (0, 0) -> 0
// (1, 0) -> 1
// (0, 1) -> 2

// then we can build the truth table
// a  b  n  a' b'
// 0  0  0  0  0
// 0  0  1  1  0
// 1  0  0  1  0
// 1  0  1  0  1
// 0  1  0  0  1
// 0  1  1  0  0

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    auto a = 0;
    auto b = 0;
    for (auto num : nums)
    {
      auto aNew = (~a & ~b & num) | (a & ~b & ~num);
      auto bNew = (a & ~b & num) | (~a & b & ~num);

      a = aNew;
      b = bNew;
    }

    return a;
  }
};