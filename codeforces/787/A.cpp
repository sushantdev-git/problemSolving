#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
// #define int long long
#define ss second
#define ff first

void solve(){
    
    long long int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    // cout<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<endl;

    if(x > a){
        x -= a;
        c -= x;
    }

    if(y > b){
        y -= b;
        c -= y;
    }

    // cout<<x<<" "<<y<<" "<<c<<endl;

    if(c >= 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}