// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int prev, vector<vector<int>> &adjs, vector<int> &cnts, vector<int> &excludeCnts)
{
  for (int neighbour : adjs[node])
  {
    if (neighbour == prev)
    {
      continue;
    }

    dfs(neighbour, node, adjs, cnts, excludeCnts);
    excludeCnts[node] += cnts[neighbour];
  }

  cnts[node] = excludeCnts[node];

  for (int neighbour : adjs[node])
  {
    if (neighbour == prev)
    {
      continue;
    }

    cnts[node] = max(cnts[node], excludeCnts[node] - cnts[neighbour] + 1 + excludeCnts[neighbour]);
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

  // cnts[i]: max number of matching of subtree i
  vector<int> cnts(n + 1, 0);
  // excludeCnts[i]: max number of matching of subtree i if we exclude the node i
  vector<int> excludeCnts(n + 1, 0);
  dfs(1, 0, adjs, cnts, excludeCnts);

  cout << cnts[1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}