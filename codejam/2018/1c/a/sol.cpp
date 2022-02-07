#include <bits/stdc++.h>
using namespace std;

void addByOne(vector<int> &encoded, vector<vector<char>> &charVectorVector)
{
  for (size_t i = 0; i < encoded.size(); i++)
  {
    int size = charVectorVector[i].size();
    if (encoded[i] == (size - 1))
    {
      encoded[i] = 0;
      continue;
    }

    encoded[i]++;
    return;
  }
}

string dfs(vector<int> encoded, vector<vector<char>> &charVectorVector, unordered_set<string> &wordSet)
{
  string word = "";
  for (size_t i = 0; i < encoded.size(); i++)
  {
    word.push_back(charVectorVector[i][encoded[i]]);
  }

  if (!wordSet.count(word))
  {
    return word;
  }

  addByOne(encoded, charVectorVector);
  return dfs(encoded, charVectorVector, wordSet);
}

void solve()
{
  int N, L;
  cin >> N >> L;
  unordered_set<string> wordSet;
  for (int i = 0; i < N; i++)
  {
    string word;
    cin >> word;
    wordSet.insert(word);
  }

  vector<unordered_set<char>> charSetVector(L, unordered_set<char>());
  for (string word : wordSet)
  {
    for (int i = 0; i < L; i++)
    {
      charSetVector[i].insert(word[i]);
    }
  }

  int count = 1;
  for (int i = 0; i < L; i++)
  {
    count *= charSetVector[i].size();
  }

  if (N == count)
  {
    cout << "-" << endl;
    return;
  }

  vector<vector<char>> charVectorVector(L, vector<char>());
  for (int i = 0; i < L; i++)
  {
    for (char c : charSetVector[i])
    {
      charVectorVector[i].push_back(c);
    }
  }

  vector<int> start(L, 0);
  string ans = dfs(start, charVectorVector, wordSet);
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