// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, int prev, vector<vector<int>> &adjs, vector<int> &ins, vector<int> &outs, int &time)
{
  time++;
  ins[node] = time;
  for (int neighbour : adjs[node])
  {
    if (neighbour == prev)
    {
      continue;
    }

    dfs(neighbour, node, adjs, ins, outs, time);
  }
  time++;
  outs[node] = time;
}

struct Node
{
  ll s;
};

void update(int node, int left, int right, int index, int value, vector<Node> &tree)
{
  if (left == right)
  {
    tree[node].s = value;
    return;
  }

  int mid = (left + right) / 2;
  if (index <= mid)
  {
    update(2 * node, left, mid, index, value, tree);
  }
  else
  {
    update(2 * node + 1, mid + 1, right, index, value, tree);
  }

  tree[node].s = tree[2 * node].s + tree[2 * node + 1].s;
}

ll query(int node, int left, int right, int queryL, int queryR, vector<Node> &tree)
{
  if (queryL <= left && queryR >= right)
  {
    return tree[node].s;
  }

  if (queryL > right || queryR < left)
  {
    return 0;
  }

  int mid = (left + right) / 2;
  return query(2 * node, left, mid, queryL, queryR, tree) + query(2 * node + 1, mid + 1, right, queryL, queryR, tree);
}

void solve()
{
  int n, q;
  cin >> n >> q;

  vector<int> vs(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    cin >> vs[i];
  }

  vector<vector<int>> adjs(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  int time = 0;
  vector<int> ins(n + 1);
  vector<int> outs(n + 1);
  dfs(1, 0, adjs, ins, outs, time);

  vector<Node> tree(1 << 20, {0});
  for (int i = 1; i < n + 1; i++)
  {
    update(1, 1, 2 * n, ins[i], vs[i], tree);
  }

  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int s, x;
      cin >> s >> x;
      update(1, 1, 2 * n, ins[s], x, tree);
    }
    if (type == 2)
    {
      int s;
      cin >> s;
      cout << query(1, 1, 2*n, ins[s], outs[s], tree) << endl;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}