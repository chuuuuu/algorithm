// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod = 1e9 + 7;

ll getHash(string word)
{
  ll ret = 0;
  for (char c : word)
  {
    ret *= 26;
    ret += (c - 'a');
    ret %= mod;
  }

  return ret;
}

void solve()
{
  string word, target;
  cin >> word >> target;

  int nWord = word.size();
  int nTarget = target.size();
  if (nWord < nTarget)
  {
    cout << 0;
    return;
  }

  ll base = 1;
  for (int i = 0; i < nTarget - 1; i++)
  {
    base *= 26;
    base %= mod;
  }
  ll hashCur = getHash(word.substr(0, nTarget));
  ll hashTarget = getHash(target);
  int curPos = 0;
  int ans = 0;
  while (true)
  {
    if (hashCur == hashTarget && word.substr(curPos, nTarget) == target)
    {
      ans++;
    }

    if (curPos + nTarget == nWord)
    {
      break;
    }

    hashCur -= base * (word[curPos] - 'a');
    hashCur *= 26;
    hashCur += word[curPos + nTarget] - 'a';
    hashCur = (hashCur % mod + mod) % mod;
    curPos++;
  }

  cout << ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}