#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n; cin>>n;

    int o = 0, z = 0;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x == 0) z ++;
        else o++;
    }

    if(o >= z) cout<<1<<endl;
    else cout<<0<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}