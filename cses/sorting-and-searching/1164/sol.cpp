// #include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using ll = long long;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval{
  int left;
  int right;
};

struct Data{
  int time;
  int index;
  bool isEnter;
};

void solve()
{
  int n;
  cin >> n;
  
  vector<Interval> intervals;
  for(int i=0; i<n; i++){
    int left, right;
    cin >> left >> right;
    intervals.push_back({left, right});
  }

  auto cmp = [](Data data1, Data data2){
    if(data1.time > data2.time){
      return true;
    }

    if(data1.time == data2.time && !data1.isEnter){
      return true;
    }

    return false;
  };

  priority_queue<Data, vector<Data>, decltype(cmp)> pq(cmp);
  for(int i=0; i<n; i++){
    auto interval = intervals[i];
    pq.push({interval.left, i, true});
  }

  int numRoom = 0;
  queue<int> emptyRooms;
  vector<int> rooms(n, -1);
  while(true){
    if(pq.empty()){
      break;
    }

    auto [time, index, isEnter] = pq.top();
    pq.pop();
    auto interval = intervals[index];

    if(isEnter){
      pq.push({interval.right, index, false});
      if(emptyRooms.empty()){
        rooms[index] = numRoom + 1;
        numRoom++;
        continue;
      }
      rooms[index] = emptyRooms.front();
      emptyRooms.pop();
      continue;
    }

    emptyRooms.push(rooms[index]);
  }

  cout << numRoom << endl;
  for(int i=0; i<n; i++){
    cout << rooms[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}