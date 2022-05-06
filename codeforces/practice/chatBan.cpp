#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int k,x;
    cin>>k>>x;

    int lo = 1, hi = 2*k-1;

    int ans = 0;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        int left =0, right = 0;

        if(mid <= k) left = mid;
        else{
            left = k;
            right = mid-k;
        }
        
        int remright = k - right;
        int rm = k*(k-1)/2 - (remright)*(remright-1)/2;
        int totalMessages = left*(left+1)/2 + rm;

        if(totalMessages == x){
            ans = mid;
            break;
        }
        else if((2*k-1 == left+right) && (totalMessages < x)) {
            ans = mid;
            break;
        }
        else if(totalMessages < x){
            ans = mid+1;
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