#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int ans = 0;
    for(int i=30; i>=0; i--){
        int x = 0;
        for(int j=0; j<n; j++){
            if(arr[j] & (1 << i)) x++;
        }

        // cout<<i<<" "<<(n - x)<<endl;
        if(x == n){
            ans |= (1 << i);
        }
        else if(n - x <= k){
            ans |= (1 << i);
            k -= (n - x);
        }

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