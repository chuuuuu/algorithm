// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int prev, vector<vector<int>> &adjs, vector<bool> &isMatchs, int &ans)
{
  for (int neighbour : adjs[node])
  {
    if (neighbour == prev)
    {
      continue;
    }

    dfs(neighbour, node, adjs, isMatchs, ans);
    if (!isMatchs[node] && !isMatchs[neighbour])
    {
      isMatchs[node] = true;
      isMatchs[neighbour] = true;
      ans++;
    }
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

  int ans = 0;
  vector<bool> isMatchs(n + 1, false);
  dfs(1, 0, adjs, isMatchs, ans);

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}