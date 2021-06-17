#include <bits/stdc++.h>
using namespace std;

int t, x, y;
string m;
int d1, d2;

void update(char c){
  d2 += 1;
  if(c == 'E'){
    if(x>=0){
      d1 += 1;
    }
    else{
      d1 -= 1;
    }
    x += 1;
    return;
  }
  else if(c == 'W'){
    if(x<=0){
      d1 += 1;
    }
    else{
      d1 -= 1;
    }
    x -= 1;
    return;
  }
  else if(c == 'N'){
    if(y>=0){
      d1 += 1;
    }
    else{
      d1 -= 1;
    }
    y += 1;
    return;
  }
  else if(c == 'S'){
    if(y<=0){
      d1 += 1;
    }
    else{
      d1 -= 1;
    }
    y -= 1;
    return;
  }
}

void solve(){
  cin >> x >> y >> m;

  d1 = x + y;
  d2 = 0;

  // cout << d1 << " " << d2 << endl;
  if(d1 == 0){
    cout << 0 << endl;
    return;
  }

  for(int i=0; i<m.size(); i++){
    update(m[i]);
    // cout << d1 << " " << d2 << endl;
    if(d1 <= d2){
      cout << d2 << endl;
      return;
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}