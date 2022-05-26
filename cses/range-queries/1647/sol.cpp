// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Node
{
  int minNum;
};

void update(int node, int left, int right, int index, int num, vector<Node> &tree)
{
  if (left == right)
  {
    tree[node].minNum = num;
    return;
  }

  int mid = (left + right) / 2;
  if (index <= mid)
  {
    update(2 * node, left, mid, index, num, tree);
  }
  else
  {
    update(2 * node + 1, mid + 1, right, index, num, tree);
  }

  tree[node].minNum = min(tree[2 * node].minNum, tree[2 * node + 1].minNum);
}

int query(int node, int left, int right, int queryL, int queryR, vector<Node> &tree)
{
  if (queryL <= left && queryR >= right)
  {
    return tree[node].minNum;
  }
  if (queryL > right || queryR < left)
  {
    return INT_MAX;
  }
  int mid = (left + right) / 2;
  return min(query(2 * node, left, mid, queryL, queryR, tree), query(2 * node + 1, mid + 1, right, queryL, queryR, tree));
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
    update(1, 1, n, i, x, tree);
  }
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << query(1, 1, n, a, b, tree) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}