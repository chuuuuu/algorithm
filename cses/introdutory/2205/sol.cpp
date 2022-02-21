#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://en.wikipedia.org/wiki/Gray_code
void solve()
{
  int n;
  cin >> n;

  vector<string> codes = {"0", "1"};
  for (int i = 2; i <= n; i++)
  {
    vector<string> newCodes(codes);
    reverse(newCodes.begin(), newCodes.end());
    codes.insert(codes.end(), newCodes.begin(), newCodes.end());
    for (int i = 0; i < codes.size() / 2; i++)
    {
      codes[i].push_back('0');
    }
    for (int i = codes.size() / 2; i < codes.size(); i++)
    {
      codes[i].push_back('1');
    }
  }

  for (string code : codes)
  {
    cout << code << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}