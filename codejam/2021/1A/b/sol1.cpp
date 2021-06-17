#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, m;
ll p[100];
ll n[100];
ll np[100];
ll s, ans;

bool check(ll x){
  ll s_tmp = s;
  ll x_tmp = x;
  for(ll i=0; i<m; i++){
    while(true){
      if(n[i] == 0){
        break;
      }
      if(x % p[i] != 0){
        break;
      }
      x = x / p[i];
      s_tmp -= p[i];
      n[i] -= 1;
      np[i] += 1;
    }
  }

  if(x != 1 || s_tmp != x_tmp){
    for(ll i=0; i<m; i++){
      n[i] += np[i];
      np[i] = 0;
    }
    return false;
  }

  ans = x_tmp;
  return true;
}

void solve(){
  cin >> m;
  for(ll i=0; i<m; i++){
    cin >> p[i] >> n[i];
    s += p[i] * n[i];
  }

  for(ll i=0; i<3e4; i++){
    if(s-i == 0){
      return;
    }
    if(check(s-i)){
      return;
    }
  }

  ans = 0;
  return;
}

int main(){
  cin >> t;
  for(ll i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << ans << endl;
    m = 0;
    s = 0;
    ans = 0;
    memset(p, 0, sizeof(p));
    memset(n, 0, sizeof(n));
    memset(np, 0, sizeof(np));
  }
}