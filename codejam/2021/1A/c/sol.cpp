// for n = 2
// we can translate the question to this:
// there are two student A, B, and a teacher
// the answer of Teacher is unknown, but it's 100% correct
// and we know
// 1. A's answer
// 2. whether B's answer is the same as A's
// now, we want to know whether Teacher's answer is the same as A's or not
// e.g.
//    1234567
// A: TTFFTFT, 4
// B: TFTFFTF, 1
// we can translate to:
//    1234567
// A: TTTTTTT, 4
// B: TFFTFFF, 1
//    14 23567
// A: TT TTTTT, 4
// B: TT FFFFF, 1
// T: 2, F:5
// as we can see, there are two kinds of question (B answers T, and B answers F)
// and we can ask that: how many (T-type question, F-type question) does A correct?
// possible (T, F) = (2, 2) or (1, 3) or (0, 4)
// however (2, 2), (1, 3) are impossible, since B only get 1 point
// (0, 4) is possible, and we can guess all of the possible answers of teacher:
// 14 23567
// FF FTTTT
// FF TFTTT
// FF TTFTT
// FF TTTFT
// FF TTTTF
// hence, to get the maximum expective score
// FF TTTTT is the best answer

#include <bits/stdc++.h>
using namespace std;

int t, n, q;
string as[3];
int ss[3];

void solve(){
  cin >> n >> q;
  for(int i=0; i<n; i++){
    cin >> as[i] >> ss[i];
  }
  
  for(int i=0; i<n; i++){
    if(ss[i] <= q/2){
      ss[i] = q-ss[i];
      string a;
      for(int j=0; j<q; j++){
        if(as[i][j] == 'T'){
          a.push_back('F');
        }
        else{
          a.push_back('T');
        }
      }
      as[i] = a;
    }
  }

  int best_i, best_s;
  best_s = -1;
  for(int i=0; i<n; i++){
    if(ss[i] > best_s){
      best_s = ss[i];
      best_i = i;
    }
  }

  cout << as[best_i] << ' ' << ss[best_i] << "/1" << endl;
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