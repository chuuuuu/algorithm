#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ABThenBA(string &word)
{
  size_t abpos = word.find("AB");
  if (abpos == string::npos)
  {
    return false;
  }

  size_t bapos = word.find("BA", abpos + 2);
  if (bapos == string::npos)
  {
    return false;
  }

  return true;
}

bool BAThenAB(string &word)
{
  size_t bapos = word.find("BA");
  if (bapos == string::npos)
  {
    return false;
  }

  size_t abpos = word.find("AB", bapos + 2);
  if (abpos == string::npos)
  {
    return false;
  }

  return true;
}

void solve()
{
  string word;
  cin >> word;

  if (ABThenBA(word) || BAThenAB(word))
  {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}