// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1000000;
vector<bool> is_primes(N, true);

void build()
{
  is_primes[0] = false;
  is_primes[1] = false;
  for (int prime = 0; prime < N; prime++)
  {
    if (!is_primes[prime])
    {
      continue;
    }

    for (int i = 2; i * prime < N; i++)
    {
      is_primes[i * prime] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
}
