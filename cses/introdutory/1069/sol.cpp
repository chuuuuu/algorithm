#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
  string word;
  cin >> word;
  char prev = word[0];
  int count = 0;
  int ans = 0;
  for (int i = 0; i < word.size(); i++)
  {
    if(word[i] == prev){
      count++;
      ans = max(ans, count);
      continue;
    }

    prev = word[i];
    count = 1;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}