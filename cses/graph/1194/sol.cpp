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

struct Data
{
  Position pos;
  bool isMonster;
};

bool isValid(Position pos, vector<vector<char>> &mp, vector<vector<bool>> &seen)
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
  vector<Position> monsters;
  Position me;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mp[i][j];
      if (mp[i][j] == 'M')
      {
        monsters.push_back({i, j});
      }
      if (mp[i][j] == 'A')
      {
        me = {i, j};
      }
    }
  }

  queue<Data> q;
  vector<vector<bool>> monsterSeen(n, vector<bool>(m, false));
  int nMonsters = monsters.size();
  for (int i = 0; i < nMonsters; i++)
  {
    monsterSeen[monsters[i].x][monsters[i].y] = true;
    q.push({monsters[i], true});
  }

  vector<vector<bool>> seen(n, vector<bool>(m, false));
  seen[me.x][me.y] = true;
  q.push({me, false});

  vector<Position> drs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  string dirs = "UDLR";
  vector<vector<int>> prevSteps(n, vector<int>(m, -1));
  while (true)
  {
    if (q.empty())
    {
      break;
    }

    auto [pos, isMonster] = q.front();
    q.pop();
    if (isMonster)
    {
      for (int i = 0; i < 4; i++)
      {
        auto &dr = drs[i];
        Position newPos = {pos.x + dr.x, pos.y + dr.y};
        if (isValid(newPos, mp, monsterSeen))
        {
          monsterSeen[newPos.x][newPos.y] = true;
          q.push({newPos, true});
        }
      }
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        auto &dr = drs[i];
        Position newPos = {pos.x + dr.x, pos.y + dr.y};
        if (isValid(newPos, mp, seen) && !monsterSeen[newPos.x][newPos.y])
        {
          seen[newPos.x][newPos.y] = true;
          prevSteps[newPos.x][newPos.y] = i;
          q.push({newPos, false});
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i != 0 && i != n - 1 && j != 0 && j != m - 1)
      {
        continue;
      }

      if (i == me.x && j == me.y)
      {
        cout << "YES" << endl
             << 0;
        return;
      }

      if (!seen[i][j])
      {
        continue;
      }

      Position cur = {i, j};
      string path;
      while (true)
      {
        if (cur.x == me.x && cur.y == me.y)
        {
          break;
        }
        int prevStep = prevSteps[cur.x][cur.y];
        path.push_back(dirs[prevStep]);
        auto &dr = drs[prevStep];
        cur = {cur.x - dr.x, cur.y - dr.y};
      }

      reverse(path.begin(), path.end());
      cout << "YES" << endl
           << path.size() << endl
           << path;
      return;
    }
  }

  cout << "NO";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}