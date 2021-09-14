#include<bits/stdc++.h>

using namespace std;
//given an array of coins value, you have to find minimum no of coins to achieve that value

int recursive(int total, vector<int>& coins, vector<int>&count){

    int mincoin = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        if(total - coins[i] < 0){
            break; 
        }
        if(count[total - coins[i]] != -1){
            mincoin = min(mincoin,count[total - coins[i]] + 1);
        }
        else{

            if(total - coins[i] >=1){
                count[total - coins[i]] = recursive(total - coins[i], coins, count);
                mincoin = min(mincoin, count[total - coins[i]]+1);
            }
            else if(total - coins[i] == 0){
                count[total - coins[i]] = 1;
                return 1;
            }
                
        }
    }

    count[total] = mincoin;
    return mincoin;
}

int iterative(int total, vector<int> & coins){

    vector<int> count(total+1, -1);

    count[0] = 0;

    for(int i = 1; i<=count.size(); i++){
        int mincoin = INT_MAX;
        for(int j=0;j<coins.size();j++){
            if(i - coins[j] < 0){
                break;
            }
            if(i - coins[j] == 0){
                mincoin = 1;
                break;
            }
            else if(i - coins[j] > 0 && count[i -coins[j]] != -1){
                
                mincoin = min(mincoin,count[i - coins[j]]+1);
            }
        }

        count[i] = mincoin == INT_MAX ? -1 : mincoin;

    }

    return count[total];
}

int main(){
    vector<int> coins = {1,2,5};
    int total = 11;

    sort(coins.begin(), coins.end());
    vector<int> count(total+1,-1);
    count[0] = 0;

    recursive(total, coins, count);
    
    cout<<count[total]<<endl;

    cout<<iterative(total, coins)<<endl;
}