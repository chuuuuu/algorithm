// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool isValid(vector<vector<char>> &mp, vector<vector<bool>> &seen, int posx, int posy)
{
  int n = mp.size();
  int m = mp[0].size();
  if (posx < 0 || posx >= n || posy < 0 || posy >= m || mp[posx][posy] == '#' || seen[posx][posy])
  {
    return false;
  }

  return true;
}

void dfs(vector<vector<char>> &mp, vector<vector<bool>> &seen, int posx, int posy)
{
  seen[posx][posy] = true;
  vector<vector<int>> drs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (auto &dr : drs)
  {
    int newPosx = posx + dr[0];
    int newPosy = posy + dr[1];
    if (isValid(mp, seen, newPosx, newPosy))
    {
      dfs(mp, seen, newPosx, newPosy);
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> mp(n, vector<char>(m, '\0'));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mp[i][j];
    }
  }

  vector<vector<bool>> seen(n, vector<bool>(m, false));
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (isValid(mp, seen, i, j))
      {
        ans++;
        dfs(mp, seen, i, j);
      }
    }
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}