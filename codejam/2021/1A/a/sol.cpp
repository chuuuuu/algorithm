#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 100;
ll t, n;
ll x[N];
ll ans;

ll head(ll a){
  while(a > 9){
    a /= 10;
  }

  return a;
}

ll digit(ll a){
  ll ret = 1;
  while(a>9){
    a = a / 10;
    ret += 1;
  }

  return ret;
}

void solve(){
  cin >> n;
  for(ll i=0; i<n; i++){
    cin >> x[i];
  }

  ans = 0;
  ll x_prev = 0;
  for(ll i=0; i<n; i++){
    if(x[i] > x_prev){
    }
    else{
      ll d_prev = digit(x_prev);
      ll d = digit(x[i]);
      if(d_prev == d){
        x[i] *= 10;
        ans += 1;
      }
      else{
        ll x_new = x[i];
        for(ll i=0; i<d_prev-d; i++){
          x_new *= 10;
        }
        ll diff = x_prev - x_new;
        // cout << x_prev << ' ' << x_new << ' ' << digit(diff) << ' ' << d_prev << ' ' << d<< endl;
        if(diff < 0){
          x[i] = x_new;
          ans += d_prev - d;
        }
        else if(digit(diff) <= (d_prev-d)){
          ll x_tmp = x_prev + 1;
          for(int j=0; j<d_prev-d; j++){
            x_tmp /= 10;
          }
          if(x_tmp != x[i]){
            x_new *= 10;
            x[i] = x_new;
            ans += d_prev - d + 1;
          }
          else{
            x_new = x_prev + 1;
            x[i] = x_new;
            ans += d_prev - d;
          }
        }
        else{
          x_new *= 10;
          x[i] = x_new;
          ans += d_prev - d + 1;
        }
      }
      // x[i] *= 10;
      // ans += 1;
      // while(x_prev - x[i] >= 9){
      //   x[i] *= 10;
      //   ans += 1;
      // }
      // if(x_prev >= x[i]){
      //   x[i] = x_prev + 1;
      // }
      // x_prev = x[i];
    }
    x_prev = x[i];
  }

  // for(ll i=0; i<n; i++){
  //   cout << x[i] << ' ';
  // }
  // cout << endl;
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