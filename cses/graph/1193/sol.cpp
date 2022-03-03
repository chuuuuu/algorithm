// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Position
{
  int x, y;
};

bool isValid(vector<vector<char>> &mp, vector<vector<bool>> &seen, Position pos)
{
  int n = mp.size();
  int m = mp[0].size();
  if (pos.x < 0 || pos.x >= n || pos.y < 0 || pos.y >= m || mp[pos.x][pos.y] == '#' || seen[pos.x][pos.y])
  {
    return false;
  }

  return true;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> mp(n, vector<char>(m));
  Position posA, posB;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mp[i][j];
      if (mp[i][j] == 'A')
      {
        posA = {i, j};
      }
      if (mp[i][j] == 'B')
      {
        posB = {i, j};
      }
    }
  }

  queue<Position> q;
  vector<vector<int>> prevSteps(n, vector<int>(m, -1));
  vector<vector<bool>> seen(n, vector<bool>(m, false));
  vector<Position> drs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  string dirs = "UDLR";
  q.push(posA);
  seen[posA.x][posA.y] = true;
  while (true)
  {
    if (q.empty())
    {
      break;
    }

    auto pos = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      auto &dr = drs[i];
      Position newPos = {pos.x + dr.x, pos.y + dr.y};
      if (isValid(mp, seen, newPos))
      {
        seen[newPos.x][newPos.y] = true;
        prevSteps[newPos.x][newPos.y] = i;
        q.push(newPos);
      }
    }
  }

  if (prevSteps[posB.x][posB.y] == -1)
  {
    cout << "NO";
    return;
  }

  string path;
  Position cur = posB;
  while (true)
  {
    if (cur.x == posA.x && cur.y == posA.y)
    {
      break;
    }

    int prevStep = prevSteps[cur.x][cur.y];
    path.push_back(dirs[prevStep]);
    cur = {cur.x - drs[prevStep].x, cur.y - drs[prevStep].y};
  }

  reverse(path.begin(), path.end());
  cout << "YES" << endl
       << path.size() << endl
       << path;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}