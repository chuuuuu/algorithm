#include <vector>
#include <bits/stdc++.h>
using namespace std;
int t, ans, l, min;
string y;

void find(int n){
  vector<string> ys;
  string yr(y);
  while(yr.length != 0){
    if(yr.)
    string yh = yr.substr(0, n)
  }

  // y_head
  string yh = y.substr(0, n);
  // y_remain
  string yr = y.substr(n);
}

void solve_even(){
  for(int i=l/2; i>0; i--){
    if(l%i == 0){
      find(i)
    }
  }
}

void solve(){
  cin >> y;
  l = y.length();

  if(l % 2 == 1){
    solve_odd();
  }

  if(l % 2 == 0){
    solve_even();
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t;
  for(ll i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << ans << endl;
  }
}