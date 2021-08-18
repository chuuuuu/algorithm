#include <bits/stdc++.h>
using namespace std;

struct dfsReturnType
{
  int score;
  int numUsedNode;
};

dfsReturnType dfs(vector<vector<int>> &trie, vector<int> &count, int index, int k, int depth)
{
  int totScore = 0;
  int totNumUsedNode = 0;
  for (auto nextIndex : trie[index])
  {
    if (nextIndex)
    {
      auto res = dfs(trie, count, nextIndex, k, depth + 1);
      totScore += res.score;
      totNumUsedNode += res.numUsedNode;
    }
  }

  int numGroup = (count[index] - totNumUsedNode) / k;
  totScore += depth * numGroup;
  totNumUsedNode += numGroup * k;
  return {totScore, totNumUsedNode};
}

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<vector<int>> trie(2e6, vector(26, 0));
  vector<int> count(2e6, 0);
  int newIndex = 1;
  for (auto i = 0; i < n; i++)
  {
    string s;
    cin >> s;

    auto index = 0;
    count[index] += 1;
    for (auto c : s)
    {
      if (!trie[index][c - 'A'])
      {
        trie[index][c - 'A'] = newIndex;
        newIndex += 1;
      }
      index = trie[index][c - 'A'];
      count[index] += 1;
    }
  }

  auto res = dfs(trie, count, 0, k, 0);
  auto ans = res.score;
  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}