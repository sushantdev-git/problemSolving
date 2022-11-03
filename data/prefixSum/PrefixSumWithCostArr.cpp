#include<bits/stdc++.h>
using namespace std;

//leetcode : 2448. Minimum Cost to Make Array Equal

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        
        vector<long long> prefL(n), prefR(n);
        
        long long psum = 0;
        
        vector<pair<int,int>> sorted;
        for(int i=0; i<n; i++){
            sorted.push_back({nums[i], cost[i]});
        }
        
        sort(sorted.begin(), sorted.end());
        
        for(int i=0; i<n-1; i++){
            psum += sorted[i].second;
            prefL[i+1] = prefL[i] + psum * (sorted[i+1].first - sorted[i].first);
        }
        
        psum = 0;
        
        for(int i=n-1; i>0; i--){
            psum += sorted[i].second;
            prefR[i-1] = prefR[i] + psum * (sorted[i].first - sorted[i-1].first);
        }
        
        long long ans = LLONG_MAX;
        
        for(int i=0; i<n; i++){
            ans = min(ans, prefL[i]+prefR[i]);
        }
        
        return ans;
    }
};