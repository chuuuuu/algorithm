// Floyd Warshall Algorithm
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll inf = 1e9 * 499 + 1;

void solve()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dists(n + 1, vector<ll>(n + 1, inf));
  for (int i = 0; i < m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    dists[a][b] = min(dists[a][b], c);
    dists[b][a] = min(dists[b][a], c);
  }

  for (int i = 1; i < n + 1; i++)
  {
    dists[i][i] = 0;
  }

  for (int k = 1; k < n + 1; k++)
  {
    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < n + 1; j++)
      {
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
      }
    }
  }

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << ((dists[a][b] == inf)? -1: dists[a][b]) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}