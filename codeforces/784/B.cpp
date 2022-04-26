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

    unordered_map<int,int> mp;
    int ans = -1;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        mp[x]++;

        if(mp[x] >= 3) ans = x;
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