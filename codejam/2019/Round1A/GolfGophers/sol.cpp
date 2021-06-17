#include <bits/stdc++.h>
using namespace std;

int t, n, m, state;
int dividers[] = {3, 5, 7, 11, 13, 16, 17};
int remainders[7];

int solve(){
  for(int i=0; i<7; i++){
    for(int j=0; j<18; j++){
      cout << dividers[i] << " ";
    }
    cout << endl;

    int s = 0;
    int tmp = 0;
    for(int j=0; j<18; j++){
      cin >> tmp;
      s += tmp;
      s %= dividers[i];
    }

    remainders[i] = s;
  }

  // for(int i=0; i<7; i++){
  //   cerr << remainders[i] << ' ';
  // }
  // cerr << endl;

  for(int i=0; i<=m; i++){
    for(int j=0; j<7; j++){
      if(i % dividers[j] != remainders[j]){
        break;
      }
      if(j == 6){
        return i;
      }
    }
  }

  return 0;
}

int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t >> n >> m;
  for(int i=0; i<t; i++){
    int ans = solve();
    cout << ans << endl;
    // cerr << ans << endl;
    cin >> state;
  }
}