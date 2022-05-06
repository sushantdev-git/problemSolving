#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m,x;
    cin>>n>>m>>x;

    int lo = 0, hi = n;

    int ts = x*n;
    
    int ans = 0;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mid*(x+1) <= ts && x+1 <= m){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout<<ans<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}