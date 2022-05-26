// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

  vector<Node> tree(1 << 20, {0});
  for (int i = 1; i < n + 1; i++)
  {
    int x;
    cin >> x;
    update(1, 1, (1 << 19), i, x, tree);
  }

  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int k, u;
      cin >> k >> u;
      update(1, 1, (1 << 19), k, u, tree);
    }
    else
    {
      int a, b;
      cin >> a >> b;
      cout << query(1, 1, (1<<19), a, b, tree) << endl;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}