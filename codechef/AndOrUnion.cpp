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
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> cnt(32, 0);

    for(int i=0; i<32; i++){
        for(int j=0; j<n; j++){
            // cout<<arr[j]<<" "<<(arr[j] & (1 << i))<<endl;
            cnt[i] += (arr[j] & (1 << i)) == 0 ? 0 : 1;
        }
    }

    int ans = 0;

    for(int i=0; i<32; i++){
        // cout<<i<<" "<<cnt[i]<<endl;
        if(cnt[i] > 1){
            ans += (1 << i);
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