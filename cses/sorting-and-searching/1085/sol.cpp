// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool isGood(vector<ll> &pres, ll delta, int k)
{
  for (int i = 0, pos = 0; i < k; i++)
  {
    ll pre = pres[pos];
    pos = upper_bound(pres.begin(), pres.end(), pre + delta) - pres.begin() - 1;
    if (pos == (int)pres.size() - 1)
    {
      return true;
    }
  }

  return false;
}

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<int> xs(n, 0);
  vector<ll> pres(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> xs[i];
    pres[i + 1] = pres[i] + xs[i];
  }

  ll left = 0;
  ll right = pres.back();
  while (true)
  {
    if(left == right){
      cout << left;
      return;
    }
    ll mid = (left + right) / 2;
    if (isGood(pres, mid, k))
    {
      right = mid;
      continue;
    }

    left = mid + 1;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}