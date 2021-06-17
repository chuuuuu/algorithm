#include <bits/stdc++.h>
using namespace std;

int t, n, k;
float ans;
vector<int> ins(30);
int l, r;
// vector<int> intervals(29);
int max1, max2, max0;


void solve(){
  cin >> n >> k;
  for(int i=0; i<n; i++){
    cin >> ins[i];
  }

  sort(ins.begin(), ins.begin()+n);

// n might only be 1!
  l = ins[0] - 1;
  r = k - ins[n-1];

  max1 = l;
  max2 = r;
  if(max2 > max1){
    int tmp = max1;
    max1 = max2;
    max2 = tmp;
  }

  max0 = l;
  if(r > max0){
    max0 = r;
  }

  for(int i=0; i<n-1; i++){
    int score = ins[i+1] - ins[i] - 1;
    if(score > max0){
      max0 = score;
    }

    if(score % 2 == 1){
      score += 1;
    }

    score = score / 2;
    if(score > max2){
      max2 = score;
      if(max2 > max1){
        int tmp = max1;
        max1 = max2;
        max2 = tmp;
      }
    }
  }

  if(max1+max2 > max0){
    max0 = max1 + max2;
  }

  ans = float(max0) / k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << ans << endl;
  }
}