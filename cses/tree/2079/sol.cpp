// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int parent, vector<vector<int>> &adjs, vector<int> &parents, vector<int> &cnts)
{
  for (int neighbour : adjs[node])
  {
    if (neighbour == parent)
    {
      continue;
    }

    parents[neighbour] = node;
    dfs(neighbour, node, adjs, parents, cnts);
    cnts[node] += cnts[neighbour];
  }
}

void solve()
{
  int n;
  cin >> n;

  vector<vector<int>> adjs(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  vector<int> parents(n + 1, 0);
  vector<int> cnts(n + 1, 1);
  dfs(1, 0, adjs, parents, cnts);

  for (int i = 1; i < n + 1; i++)
  {
    bool isCentroid = true;
    if (n - cnts[i] > n / 2)
    {
      isCentroid = false;
    }

    for (int neighbour : adjs[i])
    {
      if (neighbour == parents[i])
      {
        continue;
      }
      if (cnts[neighbour] > n / 2)
      {
        isCentroid = false;
      }
    }

    if (isCentroid)
    {
      cout << i;
      return;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}