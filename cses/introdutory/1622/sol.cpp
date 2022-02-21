#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(string &word, int pos, vector<string> &combs)
{
  if(pos == word.size()){
    combs.push_back(word);
    return;
  }
  vector<bool> seen(26, false);
  for (int i = pos; i < word.size(); i++)
  {
    if(seen[word[i] - 'a']){
      continue;
    }
    seen[word[i] - 'a'] = true;
    swap(word[pos], word[i]);
    dfs(word, pos+1, combs);
    swap(word[pos], word[i]);    
  }
}

void solve()
{
  string word;
  cin >> word;

  sort(word.begin(), word.end());
  vector<string> combs;
  dfs(word, 0, combs);

  sort(combs.begin(), combs.end());

  cout << combs.size() << endl;
  for(string comb: combs){
    cout << comb << endl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}