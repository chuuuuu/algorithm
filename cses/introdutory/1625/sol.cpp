#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<char, vector<int>> drs = {{'D', {1, 0}},
                                        {'U', {-1, 0}},
                                        {'L', {0, -1}},
                                        {'R', {0, 1}}};

bool isAvailable(int row, int col, vector<vector<bool>> &isVisited)
{
  return row >= 0 && row < 7 && col >= 0 && col < 7 && !isVisited[row][col];
}

// from 0, 0 to 6, 0
void getPathCount(int row, int col, int pos, vector<vector<bool>> &isVisited, string &path, int &count)
{
  if (row == 6 && col == 0)
  {
    if (pos == path.size())
    {
      count++;
      return;
    }

    return;
  }

  if (pos == path.size())
  {
    return;
  }

  if (!isAvailable(row + 1, col, isVisited) && !isAvailable(row - 1, col, isVisited) && isAvailable(row, col + 1, isVisited) && isAvailable(row, col - 1, isVisited))
  {
    return;
  }

  if (isAvailable(row + 1, col, isVisited) && isAvailable(row - 1, col, isVisited) && !isAvailable(row, col + 1, isVisited) && !isAvailable(row, col - 1, isVisited))
  {
    return;
  }

  for (auto &[c, dr] : drs)
  {
    if (path[pos] != c && path[pos] != '?')
    {
      continue;
    }
    int newRow = row + dr[0];
    int newCol = col + dr[1];
    if (!isAvailable(newRow, newCol, isVisited))
    {
      continue;
    }
    isVisited[newRow][newCol] = true;
    getPathCount(newRow, newCol, pos + 1, isVisited, path, count);
    isVisited[newRow][newCol] = false;
  }
}

void solve()
{
  string path;
  cin >> path;
  vector<vector<bool>> isVisited(7, vector<bool>(7, false));
  isVisited[0][0] = true;
  int count = 0;
  getPathCount(0, 0, 0, isVisited, path, count);
  cout << count;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}