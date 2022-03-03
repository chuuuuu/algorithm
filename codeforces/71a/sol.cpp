#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string word;
  cin >> word;
  if (word.size() <= 10)
  {
    cout << word << endl;
    return;
  }

  char begin = word[0];
  char end = word.back();
  cout << begin << word.size() - 2 << end << endl;
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