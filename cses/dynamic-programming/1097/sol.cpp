// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Return
{
  ll firstScore;
  ll secondScore;
};

vector<vector<bool>> seen(5000, vector<bool>(5000, false));
vector<vector<Return>> memo(5000, vector<Return>(5000, {0, 0}));

Return getMaxSocre(vector<ll> &xs, ll left, ll right)
{
  if (seen[left][right])
  {
    return memo[left][right];
  }

  if (left == right)
  {
    seen[left][right] = true;
    memo[left][right] = {xs[left], 0};
    return memo[left][right];
  }

  auto lRet = getMaxSocre(xs, left + 1, right);
  ll lMaxScore = xs[left] + lRet.secondScore;

  auto rRet = getMaxSocre(xs, left, right - 1);
  ll rMaxScore = xs[right] + rRet.secondScore;

  if (lMaxScore > rMaxScore)
  {
    seen[left][right] = true;
    memo[left][right] = {lMaxScore, lRet.firstScore};
    return memo[left][right];
  }

  seen[left][right] = true;
  memo[left][right] = {rMaxScore, rRet.firstScore};
  return memo[left][right];
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> xs(n, 0);
  for (ll &x : xs)
  {
    cin >> x;
  }

  cout << getMaxSocre(xs, 0, n - 1).firstScore;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}