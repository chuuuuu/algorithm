#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(int node, int numCat, vector<bool> &seen, vector<vector<int>> &adjs, vector<int> &hasCat, int m)
{
  seen[node] = true;
  
  numCat = hasCat[node] ? numCat + 1 : 0;
  if (numCat > m)
  {
    return 0;
  }

  bool isLeaf = true;
  for (int child : adjs[node])
  {
    if (!seen[child])
    {
      isLeaf = false;
      break;
    }
  }

  if (isLeaf)
  {
    return 1;
  }

  int ret = 0;
  for (int child : adjs[node])
  {
    if (!seen[child])
    {
      ret += dfs(child, numCat, seen, adjs, hasCat, m);
    }
  }

  return ret;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  // 1, 1, 0, 0
  vector<int> hasCat(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> hasCat[i];
  }

  // 0: {1, 2, 3}
  vector<vector<int>> adjs(n, vector<int>());
  for (int i = 0; i < n - 1; i++)
  {
    int node1, node2;
    cin >> node1 >> node2;
    adjs[node1 - 1].push_back(node2 - 1);
    adjs[node2 - 1].push_back(node1 - 1);
  }

  vector<bool> seen(n, false);
  int ans = dfs(0, 0, seen, adjs, hasCat, m);
  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}