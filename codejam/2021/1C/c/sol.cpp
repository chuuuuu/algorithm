#include <bits/stdc++.h>
using namespace std;
int t;
string s, e;
deque<string> q;
unordered_map<string, int> m;

string get_not(string n){
  string ret;
  bool first = true;
  for(int i=0; i<n.length(); i++){
    if(first){
      if(n[i] == '0'){
        ret.push_back('1');
        first = false;
      }
    }

    else{
      if(n[i] == '0'){
        ret.push_back('1');
      }
      if(n[i] == '1'){
        ret.push_back('0');
      }
    }
  }

  return ret;
}

string get_doub(string n){
  string ret(n);
  ret.push_back('0');

  return ret;
}

bool check(){
  string target(e);
  while(target.length() != 0 && target[target.length()-1] == '0'){
    target.pop_back();
  }
  while(target.length() != 0 && target[target.length()-1] == '1'){
    target.pop_back();
  }

  if(target.length() == 0){
    return true;
  }

  // cout << target << endl;

  string match(s);
  if(match.find(target) != string::npos){
    return true;
  }

  match = get_not(s);
  if(match.find(target) != string::npos){
    return true;
  }

  return false;
}

void solve(){
  cin >> s >> e;
  if(!check()){
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  q.push_back(s);
  m[s] = 0;
  // cout << s << endl;
  // cout << e << endl;
  // cout << m[e] << endl;
  while(m.find(e) == m.end()){
    string n = q[0];
    q.pop_front();
    cout << n << endl;
    string x1 = get_not(n);
    // cout << x1 << endl;
    if(m.find(x1) == m.end()){
      m[x1] = m[n] + 1;
      q.push_back(x1);
    }

    string x2 = get_doub(n);
    // cout << x2 << endl;
    if(m.find(x2) == m.end()){
      m[x2] = m[n] + 1;
      q.push_back(x2);
    }

    // cout << endl;
  }

  cout << m[e] << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    q.clear();
    m.clear();
  }
}