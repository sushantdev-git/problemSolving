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

    cout<<n<<endl;

    for(int i=1; i<=n; i++) arr[i-1] = i;

    for(auto &i: arr) cout<<i<<" ";
    cout<<endl;

    int k = n-2;
    while(k > -1){
        // cout<<k<<endl;
        swap(arr[k], arr[k+1]);
        for(auto &i: arr) cout<<i<<" ";
        cout<<endl;
        k--;
    }


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