#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF

int t, n, l, ans;
vector<pair<int, int>> num_needs;
int nums[10001];
int needs[10001];
int cache[10001];
bool visit[10001];
int need_new;

bool cmp(pair<int, int> p1, pair<int, int> p2){
  return p1.second < p2.second;
}

int get_need(int n, int num){
  if(int(100.0 / n) * n == 100){
    return INF;
  }

  if(visit[num]){
    return cache[num];
  }

  float p = float(num) / n * 100;
  if(p - int(p) >= 0.5){
    visit[num] = true;
    cache[num] = 0;
    return cache[num];
  }

  visit[num] = true;
  cache[num] = get_need(n, num+1) + 1;
  return cache[num];
}

int rnd(float p){
  int ret = int(p);

  if(p - ret >= 0.5){
    return ret+1;
  }

  return ret;
}

void solve(){
  cin >> n >> l;
  int cnt = 0;
  for(int i=0; i<l; i++){
    cin >> nums[i];
    cnt += nums[i];
  }

  need_new = get_need(n, 0);
  if(need_new == INF){
    ans = 100;
    return;
  }

  for(int i=0; i<l; i++){
    needs[i] = get_need(n, nums[i]);
    num_needs.push_back({nums[i], needs[i]});
  }

  sort(num_needs.begin(), num_needs.end(), cmp);

  for(int i=0; i<l; i++){
    if(cnt == n){
      break;
    }

    if(num_needs[i].second > need_new){
      break;
    }

    if(n - cnt < num_needs[i].second){
      num_needs[i].first += n - cnt;
      cnt += n-cnt;
      continue;
    }

    num_needs[i].first += num_needs[i].second;
    cnt += num_needs[i].second;
  }

  ans = 0;
  for(int i=0; i<l; i++){
    float p = float(num_needs[i].first) / n * 100;
    ans += rnd(p);
  }

  float p = float(need_new) / n * 100;
  ans += rnd(p) * ((n - cnt) / need_new);

  p = float((n - cnt) % need_new) / n * 100;
  ans += rnd(p);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    num_needs.clear();
    memset(visit, 0, sizeof(visit));    

    cout << "Case #" << i+1 << ": ";
    solve();
    cout << ans << endl;
  }
}