#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int head = 0;
    int tail = nums.size() - 1;
    while (true)
    {
      if (head == tail)
      {
        return head;
      }

      if (head + 1 == tail)
      {
        return nums[head] > nums[tail] ? head : tail;
      }

      int middle = (head + tail) / 2;
      if (nums[middle + 1] > nums[middle])
      {
        head = middle + 1;
        continue;
      }

      tail = middle;
    }
  }
};