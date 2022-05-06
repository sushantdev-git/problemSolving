#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first


void solve(){
    int n, k;
    cin>>n >> k;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        int x; cin>>x;
        arr[i] = pow(10,x);
    }

    int sum = 0;

    for(int i=0; i<n; i++){
        int occ = k + 1;
        if(i+1 < n) occ = min(occ, arr[i+1]/arr[i] - 1);

        sum += occ*arr[i];
        k -= occ;
    }

    cout<<sum<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}