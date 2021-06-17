// I run the code below to produce the statastic result
// ds = [0] * 10
// for i in range(40000):
//     y = random.randint(0, 1e16-1)
//     x = random.randint(0, y)
//     ds[int(str(x)[0])] += 1

// ds2 = [0, 2493, 1908, 1459, 1120, 980, 727, 566, 450, 297]
// ds16 =[0, 2522, 1846, 1388, 1119, 954, 765, 601, 466, 339]

#include <bits/stdc++.h>
using namespace std;

int t, u;
string q, r;
string ans = "AAAAAAAAAA";
unordered_set<string> cs;
vector<array<int, 2>> stats;

bool cmp(array<int, 2> a1, array<int, 2> a2){
  return a1[0] > a2[0];
}

void solve(){
  for(int i=0; i<26; i++){
    stats.push_back({0, i});
  }
  cin >> u;
  for(int i=0; i<10000; i++){
    cin >> q >> r;
    stats[r[0]-'A'][0] += 1;

    if(cs.size()<10){
      for(auto c: r){
        cs.insert({c});
      }
    }
  }
  sort(stats.begin(), stats.end(), cmp);
  // for(int i=0; i<10; i++){
  //   cout << stats[i][0] << ' ' << stats[i][1] << endl;
  // }

  for(int i=0; i<9; i++){
    ans[i+1] = 'A' + stats[i][1];
  }
  for(auto c: ans){
    cs.erase({c});
  }
  for(auto c: cs){
    ans[0] = c[0];
  }

  cout << ans << endl;
  return;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    solve();
    stats.clear();
    cs.clear();
  }
}