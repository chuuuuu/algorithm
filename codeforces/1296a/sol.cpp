#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  int numOdd = 0;
  int numEven = 0;
  for (int i = 0; i < n; i++)
  {
    if (vec[i] % 2 == 1)
    {
      numOdd++;
      continue;
    }

    numEven++;
  }

  if (numOdd % 2 == 1)
  {
    cout << "YES" << endl;
    return;
  }

  // numOdd is even
  if (numOdd == 0)
  {
    cout << "NO" << endl;
    return;
  }

  // numOdd is even, but not zero
  if (numEven == 0)
  {
    cout << "NO" << endl;
    return;
  }

  // numOdd is even, but not zero, and numEven is greater than zero
  cout << "YES" << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
}