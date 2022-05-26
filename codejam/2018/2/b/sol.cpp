// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=1000000007LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add(LL _x, LL _y, LL _mod=mod7){
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline LL sub(LL _x, LL _y, LL _mod=mod7){
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
LL mypow(LL _a, LL _x, LL _mod){
  if(_x == 0) return 1LL;
  LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
LL mymul(LL _a, LL _x, LL _mod){
  if(_x == 0) return 0LL;
  LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
const int N=502;
int dp[N][N][N], ans[N][N];
void build(){
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int r=0; r<N; r++)
        dp[i][j][r]=-1e9;
  dp[0][0][0]=0;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int r=0; r<N; r++){
        ans[i][j]=max(ans[i][j], dp[i][j][r]);
        if(dp[i][j][r] < 0) continue;
        //printf("%d %d %d = %d\n",i,j,r,dp[i][j][r]);
        if(r+1==N) continue;
        dp[i][j][r+1]=max(dp[i][j][r+1], dp[i][j][r]);
        for(int tk=1;i+r*tk<N;tk++){
          int mnj=(tk-1)*tk/2;
          if(r == 0) mnj+=tk;
          if(j+mnj>=N) break;
          dp[i+r*tk][j+mnj][r+1]=max(
            dp[i+r*tk][j+mnj][r+1], dp[i][j][r]+tk);
        }
      }
  for(int i=0; i<N; i++)
    for(int j=1; j<N; j++)
      ans[i][j]=max(ans[i][j], ans[i][j-1]);
}
int r,b;
void init(){
  r=getint();
  b=getint();
}
void solve(){
  printf("Case #%d: %d\n", ++_cs, ans[r][b]);
}
int main(){
  build();
  __ = getint();
  while(__ --){
    init();
    solve();
  }
}
