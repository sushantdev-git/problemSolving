#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n, d;
    cin>>n>>d;


    int l=0, r = n-1;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    sort(arr.begin(), arr.end());

    // for(auto &i: arr) cout<<i<<" ";
    // cout<<endl;

    int cnt = 0;
    while(l < r){
        int sum = arr[r];
        while(l < r && sum <= d){
            sum+=arr[r];
            l++;
        }
        if(sum > d) cnt++;
        r--;
    }

    cout<<cnt<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}