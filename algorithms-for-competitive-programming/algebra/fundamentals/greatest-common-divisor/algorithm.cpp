// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// or you can use std::gcd
// if a = 0, b = 0, return 0
ll greatest_common_divisor(ll a, ll b)
{
  if(a == 0 || b == 0){
    return a | b;
  }

  int shift = 0;
  while (true)
  {
    if ((a & 1) || (b & 1))
    {
      break;
    }
    a = a >> 1;
    b = b >> 1;
    shift++;
  }

  while (true)
  {
    if(b == 0){
      return a << shift;
    }
    if (!(a & 1))
    {
      a = a >> 1;
      continue;
    }
    if (!(b & 1))
    {
      b = b >> 1;
      continue;
    }
    if(a > b){
      swap(a, b);
    }
    b -= a;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
}