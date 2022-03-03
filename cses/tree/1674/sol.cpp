// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, vector<vector<int>> &childs, vector<int> &totChilds)
{
  for (int child : childs[node])
  {
    dfs(child, childs, totChilds);
    totChilds[node] += totChilds[child] + 1;
  }
}

void solve()
{
  int n;
  cin >> n;

  vector<vector<int>> childs(n + 1, vector<int>());
  for (int i = 2; i < n + 1; i++)
  {
    int parent;
    cin >> parent;
    childs[parent].push_back(i);
  }

  vector<int> totChilds(n + 1, 0);
  dfs(1, childs, totChilds);

  for (int i = 1; i < n + 1; i++)
  {
    cout << totChilds[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}