#include <bits/stdc++.h>
using namespace std;

struct Data
{
  int maxSize;
  int left;
  int right;
};

void solve()
{
  int S;
  cin >> S;
  vector<int> Ds(S, 0);
  vector<int> As(S, 0);
  vector<int> Bs(S, 0);
  for (int i = 0; i < S; i++)
  {
    cin >> Ds[i] >> As[i] >> Bs[i];
  }

  vector<int> lefts(S, 0);
  vector<int> rights(S, 0);
  for (int i = 0; i < S; i++)
  {
    lefts[i] = Ds[i] - Bs[i];
    rights[i] = Ds[i] + As[i];
  }

  // leftDP[i]: record the maximum size of array and right destination where
  // 1. left destination is data.left
  // 2. left[i] = data.left
  // 3. the i-th sign is must included and the last one sign in the array
  vector<Data> leftDP(S, {1, lefts[0], rights[0]});
  vector<Data> rightDP(S, {1, rights[0], rights[0]});
  vector<int> leftOnlyDP(S, 1);
  vector<int> rightOnlyDP(S, 1);
  for (int i = 1; i < S; i++)
  {
    // leftDP
    leftDP[i] = {rightOnlyDP[i - 1] + 1, lefts[i], rights[i - 1]};

    if (lefts[i] == leftDP[i - 1].left)
    {
      Data data = {leftDP[i - 1].maxSize + 1, leftDP[i - 1].left, leftDP[i - 1].right};
      if (data.maxSize >= leftDP[i].maxSize)
      {
        leftDP[i] = data;
      }
    }

    if (lefts[i] == rightDP[i - 1].left || rightDP[i - 1].left == INT_MAX)
    {
      Data data = {rightDP[i - 1].maxSize + 1, lefts[i], rightDP[i - 1].right};
      if (data.maxSize > leftDP[i].maxSize)
      {
        leftDP[i] = data;
      }
    }

    // rightDP
    rightDP[i] = {leftOnlyDP[i - 1] + 1, lefts[i - 1], rights[i]};

    if (rights[i] == rightDP[i - 1].right)
    {
      Data data = {rightDP[i - 1].maxSize + 1, rightDP[i - 1].left, rightDP[i - 1].right};
      if (data.maxSize >= rightDP[i].maxSize)
      {
        rightDP[i] = data;
      }
    }

    if (rights[i] == leftDP[i - 1].right || leftDP[i - 1].right == INT_MAX)
    {
      Data data = {leftDP[i - 1].maxSize + 1, leftDP[i - 1].left, rights[i]};
      if (data.maxSize > rightDP[i].maxSize)
      {
        rightDP[i] = data;
      }
    }

    // leftOnlyDP
    if (lefts[i] == lefts[i - 1])
    {
      leftOnlyDP[i] = leftOnlyDP[i - 1] + 1;
    }
    // rightOnlyDP
    if (rights[i] == rights[i - 1])
    {
      rightOnlyDP[i] = rightOnlyDP[i - 1] + 1;
    }
  }

  int maxSize = 0;
  for (int i = 0; i < S; i++)
  {
    maxSize = max(maxSize, leftDP[i].maxSize);
    maxSize = max(maxSize, rightDP[i].maxSize);
  }

  int count = 0;
  for (int i = 0; i < S; i++)
  {
    if (leftDP[i].maxSize == maxSize || rightDP[i].maxSize == maxSize)
    {
      count++;
    }
  }

  cout << maxSize << " " << count << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}