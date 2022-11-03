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

    vi arr(n);
    INP(arr, n);

    int gcd = arr[0];


    for(int i=1; i<n; i++){
        gcd = __gcd(gcd, arr[i]);
    }

    if(gcd == 1){
        cout<<0<<endl;
        return;
    }

    int ans = 0;

    for(int i=n-1; i>=0; i--){
        if(gcd > 1 && gcd != i+1){
            gcd = __gcd(gcd, i+1);
            ans += n-i;
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