#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(26, 0);
        for(char c: s){
            counts[c-'a'] += 1;
        }
        
        for(char c: t){
            counts[c-'a'] -= 1;
        }
        
        for(int i=0; i<26; i++){
            if(counts[i]){
                return false;
            }
        }
        
        return true;
    }
};