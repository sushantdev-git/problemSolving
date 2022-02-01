#include<bits/stdc++.h>
#include "./leetcodeHelper.h"
using namespace std;

class Solution {
public:
    void op(unordered_map<int, pair<int,int>> &mp, int curr, int find, int &mx){
        int pa = mp[find].first;
        mp[pa].second++;

        mp[curr] = {pa, 1};
        mx = max(mx, mp[pa].second);
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp;
        
        if(nums.size() == 0) return 0;
        
        int mx = 0;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            if(mp.find(curr) != mp.end()) continue;
            if(mp.find(curr-1) != mp.end() && mp.find(curr+1) != mp.end()){
                int pa = mp[curr-1].first;
                int pb = mp[curr+1].first;
                
                mp[pb].first = pa;
                mp[pa].second+= mp[pb].second+1;
                
                mp[curr] = {pa, 1};
                mx = max(mx, mp[pa].second);
            }
            else if(mp.find(curr-1) != mp.end()) op(mp, curr, curr-1, mx);
            else if(mp.find(curr+1) != mp.end()) op(mp, curr, curr+1, mx);
            else mp[curr] = {curr, 1};
            mx = max(mx, 1);
        }
        
        return mx;
    }
};


int main(){
    Solution ss;
    string s;

    cin>> s;
    vector<int> arr = stringArr_toIntArr(split(s, ','));

    cout<<ss.longestConsecutive(arr)<<endl;
}

/*
    10
    0 3 7 2 5 8 4 6 0 1

    6
    100 4 200 1 3 2
*/