#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, m, ans, s, prod;
vector<array<ll, 2>> prime_nums;
vector<ll> visit;

void find(ll p){
  // cout << p << ' ' << s << ' ' << prod << endl;
  if(prod == s){
    ans = max(ans, prod);
  }
  else if(prod > s){
    // prod /= p;
    // s += p;
    return;
  }
  else{ 
    for(ll i=0; i<m; i++){
      if(visit[i] != prime_nums[i][1]){
        s -= p;
        prod *= p;
        visit[i] += 1;
        find(prime_nums[i][0]);
        s += p;
        prod /= p;
        visit[i] -= 1;
      }
    }
  }
}

void solve(){
  cin >> m;
  ans = 0;
  s = 0;
  prod = 1;
  for(ll i=0; i<m; i++){
    ll p, n;
    cin >> p >> n;
    s += p*n;
    prime_nums.push_back({p, n});
    visit.push_back(0);
  }

  for(ll i=0; i<m; i++){
    if(visit[i] != prime_nums[i][1]){
      visit[i] += 1;
      find(prime_nums[i][0]);
      visit[i] -= 1;
    }
  }
}

int main(){
  cin >> t;
  for(ll i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << ans << endl;
    prime_nums.clear();
    visit.clear();
  }
}