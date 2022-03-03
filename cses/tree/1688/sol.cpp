// The time complexity of algorithm I used here is <n * log(n), log(n)>
// however the best time complexity can be <n, 1>
// see: https://www.topcoder.com/thrive/articles/Range%20Minimum%20Query%20and%20Lowest%20Common%20Ancestor

// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void dfs(int node, vector<vector<int>> &childs, vector<int> &heights)
{
  for (int child : childs[node])
  {
    heights[child] = heights[node] + 1;
    dfs(child, childs, heights);
  }
}

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

  vector<int> heights(n + 1, 0);
  dfs(1, childs, heights);

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    if (heights[a] < heights[b])
    {
      swap(a, b);
    }

    int diff = heights[a] - heights[b];
    for (int j = 0; j < 32; j++)
    {
      if (diff & (1 << j))
      {
        a = jumps[a][j];
      }
    }

    if (a == b)
    {
      cout << a << endl;
      continue;
    }

    for (int j = 31; j >= 0; j--)
    {
      if (jumps[a][j] != jumps[b][j])
      {
        a = jumps[a][j];
        b = jumps[b][j];
      }
    }

    cout << jumps[a][0] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}