#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m;
    cin>>n>>m;

    if(n == 1 && m == 1){
        cout<<0<<endl;
        return;
    }

    if(n == 1 || m == 1){
        if(abs(n-m) > 1){
            cout<<-1<<endl;
            return;
        }
    }

    int ans = 0;

    ans += 2*(min(n,m)-1);

    int curr = min(n,m);

    int rem = max(m,n) - curr;

    if(rem) ans += rem % 2 == 0 ? 2*rem : 2*rem -1 ;

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