// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n, t;
  cin >> n >> t;

  vector<ll> ks(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> ks[i];
  }

  ll maxK = -1;
  for (int i = 0; i < n; i++)
  {
    maxK = max(maxK, ks[i]);
  }

  ll right = maxK * t;
  ll left = 0;
  while(true){
    if(left == right){
      break;
    }

    ll mid = (left + right) / 2;
    ll numProdct = 0;
    for(int i=0; i<n; i++){
      numProdct += mid / ks[i];
      // avoid overflow
      if(numProdct >= t){
        break;
      }
    }

    if(numProdct >= t){
      right = mid;
      continue;
    }

    left = mid + 1;
  }

  cout << left;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}