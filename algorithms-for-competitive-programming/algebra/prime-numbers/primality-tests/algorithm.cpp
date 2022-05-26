// deterministic algorithm:
// check one by one until x = sqrt(N), time complexity O(sqrt(N)) = O(2^(number of bits / 2))
// AKS primality test gives time complexity O(poly(number of bits))

// non-deterministic algorithm
// since check one by one is too slow, and aks primality test is too hard to implement in the contest
// we can use non-deterministic algorithm which will tell us if the number is probabily a prime (with high probability)

// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll is_prime(ll number)
{
  if (number == 0 || number == 1)
  {
    return false;
  }

  for (ll x = 2; x * x <= number; x++)
  {
    if (number % x == 0){
      return false;
    }
  }

  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
}