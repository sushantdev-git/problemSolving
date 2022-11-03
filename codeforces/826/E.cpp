#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    vi arr(n);
    INP(arr, n);

    vi dp(n+1, false);
    dp[0] = true;

    for(int i=1; i<=n; i++){
        int val = arr[i-1];

        //supposing the segment is onto the left
       if(i - val -1 >= 0 && dp[i-val-1]){
            dp[i] = true;
       }

       //supposing the segment is onto the right;
       if(i + val <= n && dp[i-1]){
            dp[i+val] = true;
       }
    }

    if(dp[n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


//1 2 2 4 5 6
//6 1 3 4 5 2



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}