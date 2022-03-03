// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, vector<bool> &seen, vector<vector<int>> &adjs)
{
  seen[node] = true;
  for (int neighbour : adjs[node])
  {
    if (!seen[neighbour])
    {
      dfs(neighbour, seen, adjs);
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

  vector<bool> seen(n + 1, false);
  vector<int> parents;
  for (int i = 1; i < n + 1; i++)
  {
    if (!seen[i])
    {
      parents.push_back(i);
      dfs(i, seen, adjs);
    }
  }

  int nParents = parents.size();
  cout << nParents - 1 << endl;
  for (int i = 1; i < nParents; i++)
  {
    cout << parents[0] << ' ' << parents[i] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}