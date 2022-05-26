// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int parent, vector<vector<int>> &adjs, vector<int> &heights, vector<int> &parents)
{
  for (int neighbour : adjs[node])
  {
    if (neighbour == parent)
    {
      continue;
    }

    parents[neighbour] = node;
    heights[neighbour] = heights[node] + 1;
    dfs(neighbour, node, adjs, heights, parents);
  }
}

int getLCA(int node1, int node2, vector<vector<int>> &jumps, vector<int> &heights)
{
  if (heights[node2] > heights[node1])
  {
    swap(node1, node2);
  }

  int diff = heights[node1] - heights[node2];
  for (int i = 0; i < 32; i++)
  {
    if (diff & (1 << i))
    {
      node1 = jumps[i][node1];
    }
  }

  if (node1 == node2)
  {
    return node1;
  }

  // find the highest non-common accient
  for (int i = 31; i >= 0; i--)
  {
    if (jumps[i][node1] != jumps[i][node2])
    {
      node1 = jumps[i][node1];
      node2 = jumps[i][node2];
    }
  }

  return jumps[0][node1];
}

void solve()
{
  int n, q;
  cin >> n >> q;

  vector<vector<int>> adjs(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  // let node 1 be the root
  vector<int> heights(n + 1, 0);
  vector<int> parents(n + 1, 0);
  dfs(1, 0, adjs, heights, parents);

  vector<vector<int>> jumps(32, vector<int>(n + 1, 0));
  for (int i = 1; i < n + 1; i++)
  {
    jumps[0][i] = parents[i];
  }

  for (int i = 1; i < 32; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      jumps[i][j] = jumps[i - 1][jumps[i - 1][j]];
    }
  }

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;

    int lca = getLCA(a, b, jumps, heights);
    cout << heights[a] - heights[lca] + heights[b] - heights[lca] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}