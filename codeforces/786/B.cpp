#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    string s;
    cin>>s;

    int ans = 0;
    int a = s[0] - 'a' + 1;

    ans += 25*(a-1);

    int b = s[1] - 'a' + 1;

    if(b < a){
        ans += b;
    }
    else ans += b-1;

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