#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){

    int n, c;
    cin>>n>>c;

    unordered_map<int,int> mp;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        mp[x]++;
    }

    int cost = 0;

    for(auto &p: mp){
        int k = p.first, v = p.second;
    
        if(v > c) cost+=c;
        else cost +=v;
    }

    cout<<cost<<endl;
    
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