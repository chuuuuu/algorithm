#include <bits/stdc++.h>
using namespace std;

void solve()
{
  long long N, K;
  cin >> N >> K;

  long long totCount = 0;
  priority_queue<long long> pq;
  unordered_map<long long, long long> counts = {{N, 1}};
  long long ans1 = 0;
  long long ans2 = 0;
  pq.push(N);
  while (true)
  {
    if (totCount >= K)
    {
      break;
    }

    long long numBathroomStall = pq.top();
    pq.pop();

    // cast long long to double might loss data!
    ans1 = numBathroomStall / 2;
    ans2 = (numBathroomStall - 1) / 2;

    if (!counts.count(ans1))
    {
      counts[ans1] = 0;
      pq.push(ans1);
    }
    if (!counts.count(ans2))
    {
      counts[ans2] = 0;
      pq.push(ans2);
    }

    counts[ans1] += counts[numBathroomStall];
    counts[ans2] += counts[numBathroomStall];

    totCount += counts[numBathroomStall];
  }

  cout << ans1 << " " << ans2 << endl;
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