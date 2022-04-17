#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define ss second
#define ff first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


vector<int> dp(32769, -1);
int mod = 32768;

int minStep(int n){

    if(n <= 0) return 0;

    if(dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    int a = (n+1)%mod;
    int b = (2*n)%mod;
    
    int x = 1 + minStep(a);
    dp[n] = x;
    int y = 1 + minStep(b);

    return dp[n] = min(x,y);
}


void solve(vector<int> &dp){
    int n;
    cin>>n;

    vector<int> A(n);
    input_1darr(A,n);

    for(auto &x: A){
        cout<<minStep(x)<<" ";
    }
    cout<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve(dp);

    return 0;
}