#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> charStack;
        unordered_set<char> closedChars = {')', ']', '}'};
        unordered_map<char, char> parentheseMap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for(auto c: s){
            // opened
            if(!closedChars.count(c)){
                charStack.push(c);
                continue;
            }
            
            if(charStack.empty()){
                return false;
            }
            
            if(parentheseMap[charStack.top()] != c){
                return false;
            }
            charStack.pop();
        }
        
        if(!charStack.empty()){
            return false;
        }
        
        return true;
    }
};