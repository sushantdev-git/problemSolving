#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    int lb = n/2, ub = n;

    if(n&1) lb++;


    int i=1;
    while(i < n){
        cout<<lb<<" "<<ub<<" ";
        lb--, ub--;
        i+=2;
    }

    if(n&1){
        cout<<lb;
    }

    cout<<endl;
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