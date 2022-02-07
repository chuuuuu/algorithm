#include <bits/stdc++.h>
using namespace std;

bool create(int metal, vector<int> &counts, unordered_set<int> &isEmptyAndSeen, vector<int> &R1, vector<int> &R2)
{
  if (counts[metal])
  {
    counts[metal]--;
    return true;
  }

  isEmptyAndSeen.insert(metal);
  if (isEmptyAndSeen.count(R1[metal]))
  {
    return false;
  }

  if (isEmptyAndSeen.count(R2[metal]))
  {
    return false;
  }

  if (create(R1[metal], counts, isEmptyAndSeen, R1, R2) && create(R2[metal], counts, isEmptyAndSeen, R1, R2))
  {
    return true;
  }

  return false;
}

void solve()
{
  int M;
  cin >> M;
  vector<int> R1(M, 0);
  vector<int> R2(M, 0);
  for (int i = 0; i < M; i++)
  {
    cin >> R1[i] >> R2[i];
    R1[i]--;
    R2[i]--;
  }

  vector<int> counts(M, 0);
  for (int i = 0; i < M; i++)
  {
    cin >> counts[i];
  }

  int ans = 0;
  while (true)
  {
    unordered_set<int> isEmptyAndSeen = {};
    if (!create(0, counts, isEmptyAndSeen, R1, R2))
    {
      break;
    }

    ans++;
  }

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