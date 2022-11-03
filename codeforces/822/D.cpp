#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

unordered_map<string, bool> dp;

bool solve(int i, int j, int sum, vector<int> &arr){
    if(i < 0 || j >= arr.size()) return true;

    string key = to_string(i)+" "+to_string(j);
    if(dp.find(key) != dp.end()) return dp[key];

    if(sum + arr[i] >= 0){
        if(solve(i-1, j, sum+arr[i], arr)) return dp[key] = true;
    }
    if(sum + arr[j] >= 0){
        if(solve(i, j+1, sum+arr[j], arr)) return dp[key] = true;
    }

    return dp[key] = false;
}

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    dp.clear();

    k--;

    if(solve(k-1, k+1, arr[k], arr)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}