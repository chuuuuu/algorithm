// time complexity is O(P * log(P))

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> xs, vector<char> ds)
{
  int P = xs.size();

  // first: west, second: east
  map<int, pair<int, int>> counts;
  for (int i = 0; i < P; i++)
  {
    int x = xs[i];
    char d = ds[i];
    if (d != 'W' && d != 'E')
    {
      continue;
    }

    if (!counts.count(x))
    {
      counts[x] = {0, 0};
    }

    if (d == 'W')
    {
      counts[x].first++;
      continue;
    }

    if (d == 'E')
    {
      counts[x].second++;
    }
  }

  vector<int> sortedXs;
  for (auto &[key, val] : counts)
  {
    sortedXs.push_back(key);
  }

  int n = sortedXs.size();
  // number of people toward east
  vector<int> preEastSumCount(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
  {
    preEastSumCount[i] = preEastSumCount[i - 1] + counts[sortedXs[i - 1]].second;
  }

  // number of people toward west
  vector<int> postWestSumCount(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    postWestSumCount[i] = postWestSumCount[i + 1] + counts[sortedXs[i]].first;
  }

  int bestS = postWestSumCount[0];
  int bestX = 0;
  for (int i = 1; i < n + 1; i++)
  {
    int s = postWestSumCount[i] + preEastSumCount[i];
    int x = sortedXs[i - 1] + 1;
    if (counts.count(x))
    {
      s = postWestSumCount[i + 1] + preEastSumCount[i];
    }
    if (s > bestS)
    {
      bestS = s;
      bestX = x;
    }
  }

  cout << bestX << ' ';
}

void solve()
{
  int P, Q;
  cin >> P >> Q;
  vector<int> xs(P, 0);
  vector<int> ys(P, 0);
  vector<char> ds(P, 0);
  for (int i = 0; i < P; i++)
  {
    cin >> xs[i] >> ys[i] >> ds[i];
  }

  solve(xs, ds);
  for (char &d : ds)
  {
    if (d == 'E' || d == 'W')
    {
      d = 'X';
      continue;
    }
    if (d == 'N')
    {
      d = 'E';
      continue;
    }
    if (d == 'S')
    {
      d = 'W';
    }
  }

  solve(ys, ds);
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}