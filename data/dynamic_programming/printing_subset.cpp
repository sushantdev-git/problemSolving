#include<bits/stdc++.h>
using namespace std;

int arr[101];
int n;
int dp[101][10001];

int rec(int i, int sum){
    if(sum < 0) return 0;
    if(i >= n){
        if(sum == 0) return 1;
        return 0;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    return dp[i][sum] = rec(i+1, sum) || rec(i+1, sum-arr[i]);
}

void printElements(int i, int sum){
    if(i >= n) {
        cout<<endl;
        return;
    }

    if(rec(i+1, sum)){
        printElements(i+1, sum);
    }
    else{
        cout<<arr[i]<<" ";
        printElements(i+1, sum-arr[i]);
    }
}

void solve(){

    int target; cin>>target;

    if(rec(0, target)){
        printElements(0, target);
    }

}


int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];

    int t = 1;
    // cin>>t;
    memset(dp, -1, sizeof(dp));

    while(t--){
        solve();
    }
}