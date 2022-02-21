#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  string word;
  cin >> word;
  vector<int> counts(26, 0);
  for (char c : word)
  {
    counts[c - 'A']++;
  }

  int countOdd = 0;
  char oddChar = 0;
  for (int i = 0; i < 26; i++)
  {
    if (counts[i] % 2 == 1)
    {
      countOdd++;
      oddChar = 'A' + i;
    }
  }

  if (countOdd > 1)
  {
    cout << "NO SOLUTION";
    return;
  }

  string prefix;
  for (int i = 0; i < 26; i++)
  {
    prefix += string(counts[i] / 2, 'A' + i);
  }

  cout << prefix;
  if (countOdd)
  {
    cout << oddChar;
  }

  reverse(prefix.begin(), prefix.end());
  cout << prefix;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}