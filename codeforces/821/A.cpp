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

    int sum = 0;

    for(int i=0; i<k; i++){
        int j=i, mx = 0;
        while(j < n){
            mx = max(arr[j], mx);
            j+=k;
        }
        // cout<<i<<" "<<mx<<endl;
        sum+=mx;
    }

    cout<<sum<<endl;

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