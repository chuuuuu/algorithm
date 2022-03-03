// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs1(int node, int prev, vector<vector<int>> &adjs, vector<ll> &ins, vector<int> &cnts)
{
  for (int child : adjs[node])
  {
    if (child == prev)
    {
      continue;
    }

    dfs1(child, node, adjs, ins, cnts);
    cnts[node] += cnts[child];
    ins[node] += ins[child] + cnts[child];
  }
}

void dfs2(int node, int prev, int n, vector<vector<int>> &adjs, vector<ll> &ins, vector<int> &cnts, vector<ll> &outs)
{
  if (prev != 0)
  {
    outs[node] = outs[prev] + ins[prev] - (ins[node] + cnts[node]) + n - cnts[node];
  }

  for (int child : adjs[node])
  {
    if (child == prev)
    {
      continue;
    }

    dfs2(child, node, n, adjs, ins, cnts, outs);
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

  vector<ll> ins(n + 1, 0);
  vector<int> cnts(n + 1, 1);
  dfs1(1, 0, adjs, ins, cnts);

  vector<ll> outs(n + 1, 0);
  dfs2(1, 0, n, adjs, ins, cnts, outs);

  for (int i = 1; i < n + 1; i++)
  {
    cout << ins[i] + outs[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}