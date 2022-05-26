// time complexity is O(P ^ 2)

#include <bits/stdc++.h>
using namespace std;

int getCount(int x, vector<int> xs, vector<char> ds)
{
  int n = xs.size();
  int ret = 0;
  for (int i = 0; i < n; i++)
  {
    if (ds[i] == 'E' && xs[i] < x)
    {
      ret++;
    }
    if (ds[i] == 'W' && xs[i] > x)
    {
      ret++;
    }
  }

  return ret;
}

void solve(vector<int> xs, vector<char> ds)
{
  int n = xs.size();

  int bestX = 0;
  int bestCount = getCount(0, xs, ds);
  for (int i = 0; i < n; i++)
  {
    int x = xs[i] + 1;
    int count = getCount(x, xs, ds);
    if (count > bestCount || (count == bestCount && x < bestX))
    {
      bestX = x;
      bestCount = count;
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

    d = (d == 'N') ? 'E' : 'W';
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