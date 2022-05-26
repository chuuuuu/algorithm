#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int C;
  cin >> C;
  vector<int> counts(C, 0);
  for (int i = 0; i < C; i++)
  {
    cin >> counts[i];
  }

  if (counts[0] == 0 || counts[C - 1] == 0)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<vector<char>> toy(C, vector<char>(C, '.'));
  int nextPos = 0;
  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < counts[i]; j++)
    {
      if (nextPos == i)
      {
        nextPos++;
        continue;
      }

      if (nextPos > i)
      {
        for (int k = 0; k < nextPos - i; k++)
        {
          toy[k + 1][i + k + 1] = '/';
        }
        nextPos++;
        continue;
      }

      if (nextPos < i)
      {
        for (int k = 0; k < i - nextPos; k++)
        {
          toy[i - nextPos - k][nextPos + k] = '\\';
        }
        nextPos++;
        continue;
      }
    }
  }

  int maxRow = 1;
  for (int i = 1; i < C; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (toy[i][j] != '.')
      {
        maxRow++;
        break;
      }
    }
  }

  cout << maxRow << endl;
  for (int i = maxRow - 1; i >= 0; i--)
  {
    for (int j = 0; j < C; j++)
    {
      cout << toy[i][j];
    }
    cout << endl;
  }
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