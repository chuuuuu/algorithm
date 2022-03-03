// https://medium.com/algorithm-solving/binary-lifting-94d5338bdd2b

// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, q;
  cin >> n >> q;

  vector<vector<int>> childs(n + 1);
  vector<int> parents(n + 1, 0);
  for (int child = 2; child < n + 1; child++)
  {
    int parent;
    cin >> parent;
    childs[parent].push_back(child);
    parents[child] = parent;
  }

  vector<vector<int>> jumps(n + 1, vector<int>(32, 0));
  for (int i = 1; i < n + 1; i++)
  {
    jumps[i][0] = parents[i];
  }

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < 32; j++)
    {
      jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];
    }
  }

  for (int i = 0; i < q; i++)
  {
    int x, k;
    cin >> x >> k;
    for (int j = 0; j < 32; j++)
    {
      if(k & (1 << j)){
        x = jumps[x][j];
      }
    }

    cout << (x == 0? -1: x) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}