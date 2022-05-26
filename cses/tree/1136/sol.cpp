// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs1(int node, int parent, vector<vector<int>> &adjs, vector<int> &heights, vector<int> &parents)
{
  for (int neighbour : adjs[node])
  {
    if (neighbour == parent)
    {
      continue;
    }

    heights[neighbour] = heights[node] + 1;
    parents[neighbour] = node;
    dfs1(neighbour, node, adjs, heights, parents);
  }
}

void dfs2(int node, int parent, vector<vector<int>> &adjs, vector<int> &cnts, vector<int> &totCnts)
{
  totCnts[node] = cnts[node];
  for (int neighbour : adjs[node])
  {
    if (neighbour == parent)
    {
      continue;
    }

    dfs2(neighbour, node, adjs, cnts, totCnts);
    totCnts[node] += totCnts[neighbour];
  }
}

int getLCA(int node1, int node2, vector<int> &heights, vector<vector<int>> &jumps)
{
  if (heights[node1] < heights[node2])
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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjs(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  vector<int> heights(n + 1, 0);
  vector<int> parents(n + 1, 0);
  dfs1(1, 0, adjs, heights, parents);

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

  vector<int> cnts(n + 1, 0);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    int lca = getLCA(a, b, heights, jumps);
    cnts[a]++;
    cnts[b]++;
    cnts[lca]--;
    cnts[jumps[0][lca]]--;
  }

  vector<int> totCnts(n + 1, 0);
  dfs2(1, 0, adjs, cnts, totCnts);

  for (int i = 1; i < n + 1; i++)
  {
    cout << totCnts[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}