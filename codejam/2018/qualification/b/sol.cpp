#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int N;
  cin >> N;
  vector<int> nums(N, 0);
  for(int i=0; i<N; i++){
    cin >> nums[i];
  }

  vector<int> odds;
  vector<int> evens;
  for(int i=0; i<N; i++){
    if(i % 2 == 1){
      odds.push_back(nums[i]);
      continue;
    }

    evens.push_back(nums[i]);
  }

  sort(odds.begin(), odds.end());
  sort(evens.begin(), evens.end());

  vector<int> troubleNums(N, 0);
  for(int i=0; i<N; i++){
    if(i % 2 == 1){
      troubleNums[i] = odds[i/2];
      continue;
    }

    troubleNums[i] = evens[i/2];
  }

  int prev = -1;
  for(int i=0; i<N; i++){
    if(troubleNums[i] < prev){
      int ans = i-1;
      cout << ans << "\n";
      return;
    }

    prev = troubleNums[i];
  }

  cout << "OK\n";
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