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

    unordered_map<string,pair<int,int>> mp;

    for(int i=0; i<n; i++) cin>>arr[i];

    findCost(arr, mp, 0, n);
    int ans = 0;

    for(auto &p: mp){
        cout<<p.first<<" "<<p.ss.ff<<" "<<p.ss.ss<<endl;
        ans += p.ss.ff;
    }

    cout<<mp.size()<<endl;

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