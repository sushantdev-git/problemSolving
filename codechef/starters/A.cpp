#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int x,y,z;
    cin>>x>>y>>z;

    if(z%x == 0 && z%y == 0) cout<<"ANY"<<endl;
    else if(z % x == 0) cout<<"CHICKEN"<<endl;
    else if(z % y == 0) cout<<"DUCK"<<endl;
    else cout<<"NONE"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}