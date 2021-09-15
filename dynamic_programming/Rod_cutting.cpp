#include<bits/stdc++.h>
using namespace std;
#include<vector>

int max_profit_rec(int prices [], int n, vector<int> & max_count){

    if(n <= 0){
        return  0;
    }

    int max_P = INT_MIN;
    for(int i=0; i<n; i++){
        int price = max_count[n-i-1] != -1 ? prices[i]+ max_count[n-i-1] :prices[i]+max_profit_rec(prices, n-i-1, max_count);
        max_P = max(max_P, price);
    }

    max_count[n] = max_P;

    return max_P;
}

int max_profit_bottom_up(int *prices, int n){

    int dp[n+1];
    dp[0] = 0;

    for(int len=1; len<=n; len++){

        int ans = INT_MIN;
        for(int j=0; j<len; j++){

            int cut = j+1;
            int price = prices[j]+dp[len -cut];
            ans = max(ans,price);
        }

        dp[len] = ans;
    }

    return dp[n];
    
}

int main(){
    // given a rod of length n, and selling prices of each cutted piece .
    //we have to find maxim profit  
    
    int prices[] = {3,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(prices[0]);

    vector<int> max_count (n,-1);
    max_count[0] = 0;

    cout<<max_profit_rec(prices, n, max_count)<<endl;

    cout<<max_profit_bottom_up(prices, n)<<endl;
    
}

