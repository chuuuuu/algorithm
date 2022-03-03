#include <bits/stdc++.h>
using namespace std;

// 1 2 3 *8 7 6* 9 10
// 1 2 3 *8 7* 9 10
void solve()
{
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  int prev = 0;
  int begin;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] < prev)
    {
      break;
    }

    begin = i;
    prev = vec[i];
  }

  prev = 1e9+1;
  int end;
  for (int i = vec.size() - 1; i >= 0; i--)
  {
    if (vec[i] > prev)
    {
      break;
    }

    end = i;
    prev = vec[i];
  }

  reverse(vec.begin() + begin, vec.begin() + end + 1);
  prev = 0;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] < prev)
    {
      cout << "no" << endl;
      return;
    }
    prev = vec[i];
  }

  cout << "yes" << endl;
  // already sorted
  if (end < begin)
  {
    cout << 1 << " " << 1 << endl;
    return;
  }

  cout << begin + 1 << " " << end + 1 << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}