// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjs(n + 1, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }

  vector<bool> seen(n + 1, false);
  vector<int> prevNode(n + 1, -1);
  queue<int> q;
  q.push(1);
  seen[1] = true;
  while (true)
  {
    if (q.empty())
    {
      break;
    }

    int node = q.front();
    q.pop();
    for (int neighbour : adjs[node])
    {
      if (!seen[neighbour])
      {
        seen[neighbour] = true;
        prevNode[neighbour] = node;
        q.push(neighbour);
      }
    }
  }

  if (prevNode[n] == -1)
  {
    cout << "IMPOSSIBLE";
    return;
  }

  vector<int> path;
  path.push_back(n);
  int cur = n;
  while (true)
  {
    if(cur == 1){
      break;
    }
    cur = prevNode[cur];
    path.push_back(cur);
  }

  int nPath = path.size();
  cout << nPath << endl;
  for (int i = nPath - 1; i >= 0; i--)
  {
    cout << path[i] << ' ';
  } 
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}