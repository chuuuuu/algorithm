#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;
vector<ll> in(3);
ll delta, h, m, ns, tot;
ll h_ret, m_ret, s_ret, ns_ret;
const ll e9 = 1000 * 1000 * 1000LL;
const ll M = 60 * 720 * e9;

bool set_time(ll hh, ll mh, ll nsh, ll h){
  ll ns_tmp = 11 * nsh - 12 * hh + mh + 12 * 3600 * h  * e9;
  if(ns_tmp % 7920 != 0){
    return false;
  }

  ns = ns_tmp / 7920;
  if(ns < 0 || ns >= 60 * e9){
    // return false;
  }

  delta = 720 * ns - nsh;

  ll m_tmp = delta + mh;
  if(m_tmp % 12 != 0){
    return false;
  }

  m_tmp = (m_tmp / 12) - ns;
  if(m_tmp % (60*e9) != 0){
    return false;
  }

  m = m_tmp / (60*e9);
  if(m < 0 || m >=60){
    // return false;
  }

  ll tot = h*60*60*e9 + m*60*e9 + ns;
  if(tot<0){
    tot += M;
  }

  h_ret = tot / (60*60*e9);
  tot = tot % (60*60*e9);
  m_ret = tot / (60*e9);
  tot = tot % (60*e9);
  s_ret = tot / e9;
  ns_ret = tot % e9;

  return true;
}

bool set_time_ret(ll hh, ll mh, ll nsh){
  for(ll i=0; i<12; i++){
    if(set_time(hh, mh, nsh, i)){
      return true;
    }
  }

  return false;
}

void solve(){
  for(int i=0; i<3; i++){
    cin >> in[i];
  }
  
  do{
    if(set_time_ret(in[0], in[1], in[2])){
      return;
    }
  }while(next_permutation(in.begin(), in.end()));

  cout << "error" << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t;
  for(ll i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << h_ret << ' ' << m_ret << ' ' << s_ret << ' ' << ns_ret << endl;
  }
}