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

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    unordered_map<int,int> mp;

    for(int i=0; i<n; i++){
        mp[arr[i]] = i;
    }


    int ans = -1;

    for(auto &p1: mp){
        for(auto &p2: mp){
            if(__gcd(p1.first, p2.first) == 1){
                ans = max(ans, p1.second+p2.second+2);
            }
        }
    }

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