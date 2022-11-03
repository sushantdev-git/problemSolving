#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int a,b,c;

    cin>>a>>b>>c;

    if(c > b){
        if(a == 2*c-b) cout<<3<<endl;
        else if(a < 2*c - b) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else{
        if(a == b) cout<<3<<endl;
        else if(a < b) cout<<1<<endl;
        else cout<<2<<endl;
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