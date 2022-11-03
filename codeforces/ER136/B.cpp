#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    
    int n; cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    vector<int> ans(n);
    ans[0] = arr[0];

    for(int i=1; i<n; i++){
        int neg = ans[i-1] - arr[i];
        int pos = ans[i-1] + arr[i];
        if(neg >= 0 && neg != pos){
            cout<<-1<<endl;
            return;
        }
        ans[i] = pos;
    }

    for(auto &i: ans) cout<<i<<" ";
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