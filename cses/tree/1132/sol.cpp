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

  int farthestDistA = 0;
  int farthestNodeA = 0;
  for (int i = 1; i < n + 1; i++)
  {
    if (dists[i] > farthestDistA)
    {
      farthestDistA = dists[i];
      farthestNodeA = i;
    }
  }

  vector<int> distsA(n + 1, 0);
  dfs(farthestNodeA, 0, adjs, distsA);

  int farthestDistB = 0;
  int farthestNodeB = 0;
  for (int i = 1; i < n + 1; i++)
  {
    if (distsA[i] > farthestDistB)
    {
      farthestDistB = distsA[i];
      farthestNodeB = i;
    }
  }

  vector<int> distsB(n + 1, 0);
  dfs(farthestNodeB, 0, adjs, distsB);

  for (int i = 1; i < n + 1; i++)
  {
    cout << max(distsA[i], distsB[i]) << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}