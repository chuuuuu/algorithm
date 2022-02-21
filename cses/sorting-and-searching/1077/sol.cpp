#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  ll n, k;
  cin >> n >> k;

  vector<ll> xs(n, 0);
  for (ll i = 0; i < n; i++)
  {
    cin >> xs[i];
  }

  vector<int> sortedXs(k, 0);
  for (int i = 0; i < k; i++)
  {
    sortedXs[i] = xs[i];
  }
  sort(sortedXs.begin(), sortedXs.end());

  ordered_multiset<ll> omLeft;
  ll leftSum = 0;
  for (ll i = 0; i < (k - 1) / 2; i++)
  {
    omLeft.insert(sortedXs[i]);
    leftSum += sortedXs[i];
  }

  ordered_multiset<ll> omRight;
  ll rightSum = 0;
  for (ll i = (k - 1) / 2; i < k; i++)
  {
    omRight.insert(sortedXs[i]);
    rightSum += sortedXs[i];
  }

  ll medium = *omRight.begin();
  ll cost = abs((ll)omLeft.size() * medium - leftSum) + abs((ll)omRight.size() * medium - rightSum);
  cout << cost << ' ';

  for (ll i = k; i < n; i++)
  {
    ll xRemove = xs[i - k];
    if (xRemove < *omRight.begin())
    {
      leftSum -= xRemove;
      omLeft.erase(omLeft.find_by_order(omLeft.order_of_key(xRemove)));
    }
    else
    {
      rightSum -= xRemove;
      omRight.erase(omRight.find_by_order(omRight.order_of_key(xRemove)));
    }

    ll xInsert = xs[i];
    if (xInsert < *omRight.begin())
    {
      leftSum += xInsert;
      omLeft.insert(xInsert);
    }
    else
    {
      rightSum += xInsert;
      omRight.insert(xInsert);
    }

    while (true)
    {
      if ((ll)omLeft.size() == (k - 1) / 2)
      {
        break;
      }
      else if ((ll)omLeft.size() < (k - 1) / 2)
      {
        auto it = omRight.begin();
        leftSum += *it;
        rightSum -= *it;
        omLeft.insert(*it);
        omRight.erase(it);
      }
      else
      {
        auto it = prev(omLeft.end());
        leftSum -= *it;
        rightSum += *it;
        omRight.insert(*it);
        omLeft.erase(it);
      }
    }

    medium = *omRight.begin();
    cost = abs((ll)omLeft.size() * medium - leftSum) + abs((ll)omRight.size() * medium - rightSum);
    cout << cost << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}