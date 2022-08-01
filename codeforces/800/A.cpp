#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    string ans;
    int a,b;
    cin>>a>>b;

    char aC = '0', bC = '1';
    if(a < b){
        swap(a,b);
        swap(aC, bC);
    }
    
    while(a && b){
        int take = a/(b+1);
        ans+=string(take, aC);
        a-=take;
        ans+=string(1, bC);
        b--;
    }

    ans+=string(a, aC);

    cout<<ans<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}