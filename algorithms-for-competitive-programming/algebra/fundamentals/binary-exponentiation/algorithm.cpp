// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll myPow(ll a, ll b, ll mod)
{
  a %= mod;
  ll ret = 1;
  while (true)
  {
  	if(b == 0){
      break;
    }
    
    if(b & 1){
      ret *= a;
      ret %= mod;
    }
    b = b >> 1;
    a *= a;
    a %= mod;
  }

  return ret;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
}