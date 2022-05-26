// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find x, y
// s.t. ax + by = gcd(a, b)

// we want a always smaller than b
// suppose we know that
// (b % a)x_ + a * y_ = gcd(a, b)
// (b - (b/a) * a)x_ + a * y_ = gcd(a, b)
// (y_ - (b/a) * x_)a + x_ * b = gcd(a, b)

// notice that we can extend this algorithm into more general form:
// given a, b, c, find x and y such that ax + by = c
// since c must be gcd(a, b) * n, where n is an integer
// we can easily to get x, y
ll greatest_common_divisor(ll a, ll b, ll &x, ll &y)
{
  if(a == 0){
    x = 0;
    y = 1;
    return b;
  }
  ll x_, y_;
  ll ret = greatest_common_divisor(b % a, a, x_, y_);
  x = y_ - (b / a) * y_;
  y = x_;
  return ret;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

}