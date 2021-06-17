#include <bits/stdc++.h>
using namespace std;

const int NxL = 5e4;
int t, n, ans;
int counts[NxL];
// trie[0] is root
// trie[i][j] is the node
int trie[NxL][26];

void solve(){
  cin >> n;
  int unused_idx = 1;
  for(int i=0; i<n; i++){
    string w;
    cin >> w;
    int node = 0;
    for(int i=w.size()-1; i>=0; i--){
      if(trie[node][w[i]-'A'] == 0){
        trie[node][w[i]-'A'] = unused_idx;
        unused_idx += 1;
      }
      node = trie[node][w[i]-'A'];
    }  
    counts[node] += 1;
  }

  ans = 0;
  for(int i=unused_idx-1; i>0; i--){
    for(int j=0; j<26; j++){
      if(trie[i][j] != 0){
        counts[i] += counts[trie[i][j]];
      }
    }
    if(counts[i] >= 2){
      counts[i] -= 2;
      ans += 2;
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
    cout << ans << '\n';

    memset(counts, 0, sizeof(counts));
    memset(trie, 0, sizeof(trie));
  }
}