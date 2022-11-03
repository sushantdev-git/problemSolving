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
    vi h(n);
    INP(h, n);

    vi sp(n);
    INP(sp, n);

    sort(sp.begin(), sp.end());
    
    int ans = 0;

    for(int i=0; i<n-1; i++){
        ans += sp[i];
    }
    

    for(auto &i: h) ans += i;

    cout<<ans<<endl;


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