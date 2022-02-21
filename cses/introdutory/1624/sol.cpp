#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(vector<vector<char>> &board, int row, int col)
{
  if (board[row][col] == '*')
  {
    return false;
  }
  if (board[row][col] == 'Q')
  {
    return false;
  }
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (board[i][j] != 'Q')
      {
        continue;
      }
      if (i == row || j == col || abs(i - row) == abs(j - col))
      {
        return false;
      }
    }
  }

  return true;
}

int getCount(int row, vector<vector<char>> &board)
{
  if (row == 8)
  {
    return 1;
  }

  int ret = 0;
  for (int i = 0; i < 8; i++)
  {
    if (isValid(board, row, i))
    {
      board[row][i] = 'Q';
      ret += getCount(row+1, board);
      board[row][i] = '.';
    }
  }

  return ret;
}

void solve()
{
  vector<vector<char>> board(8, vector<char>(8, '.'));
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cin >> board[i][j];
    }
  }

  cout << getCount(0, board);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}