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
    int n; cin>>n;

    int r1, r2, r3, c1, c2, c3;
    cin>>r1>>c1>>r2>>c2>>r3>>c3;

    unordered_map<int,int> r, c;
    r[r1]++, r[r2]++, r[r3]++;
    c[c1]++, c[c2]++, c[c3]++;

    int px, py; //pivot cricket
    for(auto &p: r) {
        if(p.second == 2){
            px = p.first;
        }
    }
    
    for(auto &p: c) {
        if(p.second == 2){
            py = p.first;
        }
    }


    int tx, ty; cin>>tx>>ty;

    // cout<<tx<<" "<<ty<<" "<<px<<" "<<py<<endl;

    set<pair<int,int>> corners;
    corners.insert({1,n});
    corners.insert({1,1});
    corners.insert({n,1});
    corners.insert({n,n});

    if(corners.count({px, py})){
        if(tx == px || ty == py) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        if((px & 1) == (tx & 1) || (py & 1) == (ty & 1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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