#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int N;
  cin >> N;

  vector<int> counts(N, 0);
  int totCount = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> counts[i];
    totCount += counts[i];
  }

  if(N == 2){
    for(int i=0; i<counts[0]; i++){
      cout << "AB ";
    }
    cout << '\n';
    return;
  }

  auto cmp = [&counts](int party1, int party2)
  {
    return counts[party1] < counts[party2];
  };

  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  for (int i = 0; i < N; i++)
  {
    pq.push(i);
  }

  while (true)
  {
    if (totCount == 2)
    {
      break;
    }
    int party = pq.top();
    pq.pop();

    counts[party]--;
    totCount--;
    cout << char('A' + party) << ' ';

    if (counts[party])
    {
      pq.push(party);
    }
  }

  int party1 = pq.top();
  pq.pop();
  int party2 = pq.top();
  pq.pop();

  cout << char('A' + party1) << char('A' + party2) << "\n";
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