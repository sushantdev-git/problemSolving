#include<bits/stdc++.h>
using namespace std;

 bool canCross(vector<int>& stones) {
        
        set<int> stone;
        for(int i=0; i<stones.size(); i++){
            stone.insert(stones[i]);
        }
        unordered_map<int,set<int>> mp;
        mp[0].insert(1);
        
        for(int i=0; i<stones.size(); i++){
            

            for(auto jump: mp[stones[i]]){

                
                int pos = stones[i]+jump;
                if(pos == stones[stones.size() - 1]){
                    return true;
                }
                if(stone.find(pos) != stone.end()){
                    if(jump -1  > 0){
                        mp[pos].insert(jump -1);
                    }
                    mp[pos].insert(jump);
                    mp[pos].insert(jump+1);
                }
            }
            
        }
        
        
        return false;
        
    }


int main(){

    int n = 1000;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<canCross(arr);
    return 0;
}