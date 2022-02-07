#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(0);
        for(auto num: nums){
            int sum = dp.back();
            if(sum > 0){
                dp.push_back(sum+num);
                continue;
            }
            
            dp.push_back(num);
        }
        
        int ret = -10001;
        for(int i=1; i<dp.size(); i++){
            ret = max(dp[i], ret);
        }        
        
        return ret;
    }
};