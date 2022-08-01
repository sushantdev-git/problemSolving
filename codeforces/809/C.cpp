#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    int ans1 = 0, ans2 = INT_MAX;

    for(int i=1; i<n-1; i+=2){
        int mx = max(arr[i-1], arr[i+1]);
        if(mx >= arr[i]) ans1+=(mx - arr[i])+1;
    }
    if(n%2 != 0){
        cout<<ans1<<endl;
        return;
    }

    vector<int> pre(n, 0);
    vector<int> suf(n, 0);
    vector<int> diff(n, 0);

    for(int i=1; i<n-1; i++){
        int mx = max(arr[i-1], arr[i+1]);
        diff[i] = max(0LL, mx-arr[i]+1);
    }


    for(int i=1; i<n-1; i+=2){
        pre[i] = pre[i-1]+diff[i];
        pre[i+1] = pre[i];
    }

    for(int i=n-2; i>1; i-=2){
        suf[i] = suf[i+1]+diff[i];
        suf[i-1] = suf[i];
    }

    int ans = LLONG_MAX;

    for(int i=0; i<n-1; i++){
        ans = min(ans, pre[i]+suf[i+1]);
    }
    cout<<ans<<endl;
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