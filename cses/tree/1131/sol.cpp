// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int prev, vector<vector<int>> &adjs, vector<int> &dists)
{
  for (int neighbour : adjs[node])
  {
    if (neighbour == prev)
    {
      continue;
    }

    dists[neighbour] = dists[node] + 1;
    dfs(neighbour, node, adjs, dists);
  }
}

void solve()
{
  int n;
  cin >> n;

  vector<vector<int>> adjs(n + 1, vector<int>());
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  vector<int> dists(n + 1, 0);
  dfs(1, 0, adjs, dists);

  int farthestDist = 0;
  int farthestNode = 0;
  for (int i = 1; i < n + 1; i++)
  {
    if (dists[i] > farthestDist)
    {
      farthestDist = dists[i];
      farthestNode = i;
    }
  }

  dists[farthestNode] = 0;
  dfs(farthestNode, 0, adjs, dists);

  farthestDist = 0;
  farthestNode = 0;
  for (int i = 1; i < n + 1; i++)
  {
    if (dists[i] > farthestDist)
    {
      farthestDist = dists[i];
      farthestNode = i;
    }
  }

  cout << farthestDist;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}