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
    if(n == 3) cout<<-1<<endl;
    else if(n ==2) cout<<2<<" "<<1<<endl;
    else{
        int l = n%2;
        for(int i=n; i>n/2+l; i--) cout<<i<<" ";
        for(int i=1; i<=n/2+l; i++) cout<<i<<" ";
        cout<<endl;
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