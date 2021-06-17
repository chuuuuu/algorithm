#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, ans;
// since x[i] would be more than 10^9 * 10^100, we cannot store them into long long
string xs[100];

bool cmp(string s1, string s2){
  if(s1.size() > s2.size()){
    return true;
  }
  else if(s1.size() < s2.size()){
    return false;
  }
  else{
    for(int i=0; i<s1.size(); i++){
      if(s1[i] - s2[i] > 0){
        return true;
      }
      else if(s1[i] - s2[i] < 0){
        return false;
      }
    }
  }
  // equal
  return false;
}

void solve(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> xs[i];
  }

  ans = 0;
  for(int i=1; i<n; i++){
    // {12, 5, 33}, 123
    if(xs[i].size() > xs[i-1].size()){
      continue;
    }
    // 123, {132, 111, 152, 644}
    else if(xs[i].size() == xs[i-1].size()){
      // 123, 666
      if(cmp(xs[i], xs[i-1])){
        continue;
      } 
      // 123, 100
      // 123, 123 
      else{
        ans += 1;
        xs[i].push_back('0');
      }
    }
    // 123, {12, 1, 99}
    // 129, {1, 12, 13, 66}
    else{
      bool same_prefix = true;
      string x = xs[i-1];
      for(int j=x.size()-1; j>=0; j--){
        if(x[j] == '9'){
          x[j] = '0';
        }
        else{
          x[j] = char(int(x[j])+1);
          break;
        }
      }

      // 99, x
      if(x[0] == '0'){
        x.insert(0, "1");
      }

      for(int j=0; j<xs[i].size(); j++){
        if(xs[i][j] != x[j]){
          same_prefix = false;
          break;
        }
      }
      
      // 123, {12, 1}
      if(same_prefix){
        ans += x.size() - xs[i].size();
        xs[i] = x;
      }
      else{
        int dd = xs[i-1].size() - xs[i].size();
        ans += dd;
        for(int j=0; j < dd; j++){
          xs[i].push_back('0');
        }

        // 123, 666
        if(cmp(xs[i], xs[i-1])){
          continue;
        } 
        // 123, 122
        // 123, 123 
        else{
          ans += 1;
          xs[i].push_back('0');
        }
      }
    }
  }
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