#include<iostream>
#include<vector>
using namespace std;

//in this problem we are given wines price we have to find maximum price for selling the wine.
//each year you can sell only single wine, every year wine price become y*winePrice[i], where y is year,
//you can sell wine from only left or right.

int findMaxiumProfit(vector<int> &winesPrice){

    int n = winesPrice.size();
    int dp[n][n] = {0};

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i == 0){
                dp[i+j][j] = winesPrice[j]*n;
            }
            else{
                dp[j-i][j] = max((n-i)*winesPrice[j-i]+ dp[j-1][j], (n-i)*winesPrice[j] + dp[j-i][j-1]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[0][n-1];
}

int main(){

    vector<int> winesPrice = {2,3,5,1,4};

    cout<<findMaxiumProfit(winesPrice)<<endl;

    return -1;
}