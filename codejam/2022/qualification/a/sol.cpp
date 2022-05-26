#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int R, C;
  cin >> R >> C;
  vector<vector<char>> mp(2 * R + 1, vector<char>(2 * C + 1));
  for (int i = 0; i < 2 * R + 1; i++)
  {
    for (int j = 0; j < 2 * C + 1; j++)
    {
      if (i & 1)
      {
        if (j & 1)
        {
          mp[i][j] = '.';
        }
        else
        {
          mp[i][j] = '|';
        }
      }
      else
      {
        if (j & 1)
        {
          mp[i][j] = '-';
        }
        else
        {
          mp[i][j] = '+';
        }
      }
    }
  }

  mp[0][0] = '.';
  mp[0][1] = '.';
  mp[1][0] = '.';

  for (int i = 0; i < 2 * R + 1; i++)
  {
    for (int j = 0; j < 2 * C + 1; j++)
    {
      cout << mp[i][j];
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
    cout << "Case #" << i + 1 << ": " << endl;
    solve();
  }
}