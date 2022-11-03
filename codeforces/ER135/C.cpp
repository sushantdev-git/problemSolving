#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

int cntdig(int n){
    if(!n) return 0;
    return 1 + cntdig(n/10);
}

void solve(){
    int n;
    cin>>n;

    priority_queue<int> apq, bpq;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        apq.push(x);
    }

    for(int i=0; i<n; i++){
        int x; cin>>x;
        bpq.push(x);
    }

    int ans = 0;
    while(apq.size() && bpq.size()){
        int atp = apq.top(); apq.pop();
        int btp = bpq.top(); bpq.pop();

        // cout<<atp<<" "<<btp<<endl;

        if(atp > btp){
            apq.push(cntdig(atp));
            bpq.push(btp);
            ans++;
        }

        if(btp > atp){
            apq.push(atp);
            bpq.push(cntdig(btp));
            ans++;
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