#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    vector<vector<int>> q;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        q.push_back({x-1,y-1});
    }

    vector<int> pref(n);
    vector<int> suff(n);
    pref[0] = 0;
    suff[n-1] = 0;

    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            pref[i] = arr[i-1] - arr[i] + pref[i-1];
        }
        else pref[i] = pref[i-1];
    }

    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            suff[i] = arr[i+1] - arr[i] + suff[i+1];
        }
        else suff[i] = suff[i+1];
    }

    // for(auto &i: pref) cout<<i<<" ";
    // cout<<endl;


    for(auto &qq: q){
        if(qq[0] < qq[1]) cout<<pref[qq[1]] - pref[qq[0]]<<endl;
        else cout<<suff[qq[1]] - suff[qq[0]]<<endl;
    }

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}