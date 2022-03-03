// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int color, vector<vector<int>> &adjs, vector<int> &colors)
{
  colors[node] = color;
  for (int neighbour : adjs[node])
  {
    if (colors[neighbour] == 0)
    {
      dfs(neighbour, 3 - color, adjs, colors);
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjs(n + 1, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  // 0: unseen, 1: red, 2: blue
  vector<int> colors(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    if (colors[i] == 0)
    {
      dfs(i, 1, adjs, colors);
    }
  }

  for (int node = 1; node < n + 1; node++)
  {
    for (int neighbour : adjs[node])
    {
      if (colors[node] == colors[neighbour])
      {
        cout << "IMPOSSIBLE";
        return;
      }
    }
  }

  for (int i = 1; i < n + 1; i++)
  {
    cout << colors[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}