#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    int mx = 0;
    int cost = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mx= max(mx, arr[i]);
        cost += ceil(arr[i]*1.0/k);
    }

    cout<<min(mx, cost)<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}