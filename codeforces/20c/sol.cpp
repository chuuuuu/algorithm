#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Data
{
  ll dist;
  int node;
  int prevNode;
};

auto cmp = [](Data &data1, Data &data2)
{
  return data1.dist > data2.dist;
};

void update(int node, vector<bool> &seen, vector<ll> &dists, priority_queue<Data, vector<Data>, decltype(cmp)> &pq, vector<vector<pair<int, int>>> &adjs)
{
  seen[node] = true;
  for (auto [neighbour, weight] : adjs[node])
  {
    if (seen[neighbour])
    {
      continue;
    }

    ll newDist = dists[node] + weight;
    pq.push({newDist, neighbour, node});
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adjs(n, vector<pair<int, int>>());
  for (int i = 0; i < m; i++)
  {
    int node1, node2, weight;
    cin >> node1 >> node2 >> weight;
    adjs[node1 - 1].push_back({node2 - 1, weight});
    adjs[node2 - 1].push_back({node1 - 1, weight});
  }

  vector<bool> seen(n, false);
  vector<ll> dists(n, 1e11 + 1);
  dists[0] = 0;
  vector<int> prevNodes(n, 0);

  priority_queue<Data, vector<Data>, decltype(cmp)> pq(cmp);
  update(0, seen, dists, pq, adjs);
  while (true)
  {
    if (pq.empty())
    {
      break;
    }

    auto [dist, node, prevNode] = pq.top();
    pq.pop();
    if (seen[node])
    {
      continue;
    }

    prevNodes[node] = prevNode;
    dists[node] = dist;
    update(node, seen, dists, pq, adjs);
  }

  if (dists.back() == 1e11 + 1)
  {
    cout << -1;
    return;
  }

  int node = n - 1;
  vector<int> ans = {node};
  while (true)
  {
    if (node == 0)
    {
      break;
    }

    node = prevNodes[node];
    ans.push_back(node);
  }

  for (int i = ans.size() - 1; i >= 0; i--)
  {
    cout << ans[i] + 1 << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}