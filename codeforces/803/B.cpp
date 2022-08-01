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
    for(auto &i: arr) cin>>i;

    if(k == 1){
        if(n%2 == 0) cout<<n/2-1<<endl;
        else cout<<n/2<<endl;
        return;
    }

    int cnt = 0;
    for(int i=1; i<n-1; i++){
        cnt += arr[i] > arr[i-1]+arr[i+1] ? 1 : 0;
    }

    cout<<cnt<<endl;

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