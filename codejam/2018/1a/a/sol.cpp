#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int R, C, H, V;
  cin >> R >> C >> H >> V;

  vector<vector<bool>> hasChip(R, vector<bool>(C, false));
  int totChip = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      char c;
      cin >> c;
      if (c == '@')
      {
        hasChip[i][j] = true;
        totChip++;
      }
    }
  }

  if (totChip == 0)
  {
    cout << "POSSIBLE\n";
    return;
  }

  int numberChipPerBlock = totChip / (H + 1) / (V + 1);
  if (numberChipPerBlock * (H + 1) * (V + 1) != totChip)
  {
    cout << "IMPOSSIBLE\n";
    return;
  }

  int numberChipPerRow = numberChipPerBlock * (V + 1);
  // rowCut store the indexes which should be cut
  // the index should be cut means we should cut between index and index+1
  vector<int> rowCut;
  int chipSum = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (hasChip[i][j])
      {
        chipSum++;
      }
    }

    if (chipSum == numberChipPerRow)
    {
      rowCut.push_back(i);
      chipSum = 0;
      continue;
    }

    if (chipSum > numberChipPerRow)
    {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }

  vector<int> chipSums(H + 1, 0);
  for (int i = 0; i < C; i++)
  {
    int index = 0;
    for (int j = 0; j < R; j++)
    {
      if (j > rowCut[index])
      {
        index++;
      }

      if (hasChip[j][i])
      {
        chipSums[index]++;
      }
    }

    bool isFinished = true;
    for (int j = 0; j < H + 1; j++)
    {
      if (chipSums[j] > numberChipPerBlock)
      {
        cout << "IMPOSSIBLE\n";
        return;
      }

      if (chipSums[j] != numberChipPerBlock)
      {
        isFinished = false;
      }
    }

    if (!isFinished)
    {
      continue;
    }

    for (int j = 0; j < H + 1; j++)
    {
      chipSums[j] = 0;
    }
  }

  cout << "POSSIBLE\n";
  return;
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