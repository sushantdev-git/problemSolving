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
    int n, m;
    cin>>n>>m;

    set<int> r, c;
    vector<pair<int,int>> arr;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        r.insert(x);
        c.insert(y);
    }

    if(r.size() < n){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
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