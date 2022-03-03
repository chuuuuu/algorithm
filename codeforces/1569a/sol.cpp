#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;

  string word;
  cin >> word;

  char prev = word[0];
  for (int i = 1; i < word.size(); i++)
  {
    if (word[i] != prev)
    {
      cout << i << " " << i + 1 << endl;
      return;
    }

    prev = word[i];
  }

  cout << "-1 -1" << endl;
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