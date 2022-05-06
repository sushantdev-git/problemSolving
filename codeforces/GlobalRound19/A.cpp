#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int mx = 0;
    for(int i=0; i<n; i++){
        if(arr[i] < mx){
            cout<<"YES"<<endl;
            return;
        }
        mx = max(mx, arr[i]);
    }

    cout<<"NO"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}