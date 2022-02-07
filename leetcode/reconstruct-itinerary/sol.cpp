#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // preprocessing
        unordered_set<string> citySet;
        for(auto ticket: tickets){
            string city1 = ticket[0];
            string city2 = ticket[1];
            citySet.insert(city1);
            citySet.insert(city2);
        }
        
        vector<string> cities;
        for(auto city: citySet){
            cities.push_back(city);
        }
        
        sort(cities.begin(), cities.end());
        
        unordered_map<string, int> cityToIndex;
        int size = cities.size();
        for(int i=0; i<size; i++){
            cityToIndex[cities[i]] = i;
        }

        vector<queue<int>> neighbourss(size, queue<int>());
        for(auto ticket: tickets){
            string city1 = ticket[0];
            string city2 = ticket[1];
            int index1 = cityToIndex[city1];
            int index2 = cityToIndex[city2];
            
            neighbourss[index1].push(index2);
        }
        
        string startCity = "JFK";
        int start = cityToIndex[startCity];
        vector<int> path;
        dfs(start, neighbourss, path);
        
        reverse(path.begin(), path.end());
        vector<string> ret;
        for(auto cityId: path){
            ret.push_back(cities[cityId]);
        }
        
        return ret;
    }
    
    void dfs(int node, vector<queue<int>>& neighbourss, vector<int>& path){
        auto neighbours = neighbourss[node];
        while(true){
            if(neighbours.empty()){
                break;
            }
            
            int neighbour = neighbours.front();
            neighbours.pop();
            dfs(neighbour, neighbourss, path);
        }
        
        path.push_back(node);
    }
};