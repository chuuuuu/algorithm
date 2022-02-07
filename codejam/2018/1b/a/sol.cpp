#include <bits/stdc++.h>
using namespace std;

double divide(int x, int y)
{
  return double(x) / y;
}

void solve()
{
  int N, L;
  cin >> N >> L;
  vector<int> Cs(L, 0);
  int count = 0;
  for (int i = 0; i < L; i++)
  {
    cin >> Cs[i];
    count += Cs[i];
  }

  int ans = 0;
  priority_queue<double> pq;
  for (int i = 0; i < L; i++)
  {
    double percentage = divide(100 * Cs[i], N);
    ans += round(percentage);
    if (round(percentage) == int(percentage))
    {
      pq.push(percentage - round(percentage));
    }
  }

  while (true)
  {
    if (count == N)
    {
      break;
    }

    if (pq.empty())
    {
      pq.push(0);
    }

    double percentage = pq.top();
    pq.pop();

    percentage += divide(100, N);
    count++;

    ans += round(percentage);
    if (round(percentage) == int(percentage))
    {
      pq.push(percentage - round(percentage));
    }
  }

  cout << ans << "\n";
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