// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int prev, vector<vector<int>> &adjs, vector<bool> &seen, vector<int> &path, vector<int> &cycle)
{
  path.push_back(node);
  seen[node] = true;
  for (int neighbour : adjs[node])
  {
    if (neighbour == prev)
    {
      continue;
    }

    if (!seen[neighbour])
    {
      dfs(neighbour, node, adjs, seen, path, cycle);
      continue;
    }

    if (!cycle.size())
    {
      int nPath = path.size();
      int start = 0;
      for (int i = 0; i < nPath; i++)
      {
        if (path[i] == neighbour)
        {
          start = i;
          break;
        }
      }

      for (int i = start; i < nPath; i++)
      {
        cycle.push_back(path[i]);
      }
      cycle.push_back(neighbour);
    }
  }

  path.pop_back();
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

  vector<bool> seen(n + 1, false);
  vector<int> path;
  vector<int> cycle;
  for (int i = 1; i < n + 1; i++)
  {
    if (!seen[i])
    {
      dfs(i, 0, adjs, seen, path, cycle);
    }
  }

  int nCycle = cycle.size();
  if(!nCycle){
    cout << "IMPOSSIBLE";
    return;
  }

  cout << nCycle << endl;
  for(int node: cycle){
    cout << node << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}