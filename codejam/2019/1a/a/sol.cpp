#include <bits/stdc++.h>
using namespace std;

using Point = array<int, 2>;

int t, m, n;
// array<T> is a very thin wrapper around C++ arrays, hence, it is efficient
// you cannot store C-array in std container, but you can store STL-array
vector<Point> ans;
vector<Point> nodes;
bool visited[20][20];

bool is_edge(Point node1, Point node2){
  if(node1[0] == node2[0]){
    return false;
  }

  if(node1[1] == node2[1]){
    return false;
  }

  // (0, 1), (1, 0)
  if(node1[0]+node1[1] == node2[0]+node2[1]){
    return false;
  }

  // (0, 0), (1, 1)
  if(node1[0]-node1[1] == node2[0]-node2[1]){
    return false;
  }

  return true;
}

bool dfs(Point node){
  visited[node[0]][node[1]] = true;
  ans.push_back(node);

  if(ans.size() == m*n){
    return true;
  }

  for(Point node_next: nodes){
    if(!visited[node_next[0]][node_next[1]] and is_edge(node, node_next)){
      if(dfs(node_next)){
        return true;
      }
    }
  }

  visited[node[0]][node[1]] = false;
  ans.pop_back();

  return false;
}

bool solve(){
  cin >> m >> n;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      // {i, j}: initialize Point
      nodes.push_back({i, j});
      visited[i][j] = false;
    }
  }

  // you can run `time ./sol < in` in bash to test the time spent.
  // and i think it need some luck to pass the baseline.
  shuffle(nodes.begin(), nodes.end(), mt19937(0));
  for(Point node: nodes){
    if(dfs(node)){
      return true;
    }    
  }

  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for(int i=0; i<t; i++){
    cout << "Case #" << i+1 << ": ";
    if(solve()){
      cout << "POSSIBLE\n";
      for(Point pos: ans){
        cout << pos[0]+1 << " " << pos[1]+1 << "\n";
      }
    }
    else{
      cout << "IMPOSSIBLE\n";
    }

    ans.clear();
    nodes.clear();
  }
}