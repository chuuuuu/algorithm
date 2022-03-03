// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Adjacent
{
  int node;
  int weight;
};

struct Data
{
  int node;
  ll dist;
};

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<Adjacent>> adjs(n + 1, vector<Adjacent>());
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adjs[a].push_back({b, c});
  }

  vector<ll> dists(n + 1, -1);
  auto cmp = [](Data data1, Data data2)
  {
    return data1.dist > data2.dist;
  };
  priority_queue<Data, vector<Data>, decltype(cmp)> pq(cmp);

  pq.push({1, 0});

  while (true)
  {
    if (pq.empty())
    {
      break;
    }

    auto [node, dist] = pq.top();
    pq.pop();

    if (dists[node] != -1)
    {
      continue;
    }

    dists[node] = dist;

    for (auto [neighbour, weight] : adjs[node])
    {
      if (dists[neighbour] == -1)
      {
        pq.push({neighbour, dists[node] + weight});
      }
    }
  }

  for(int i=1; i<n+1; i++){
    cout << dists[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}