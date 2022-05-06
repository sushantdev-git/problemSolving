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
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.rbegin(), arr.rend());

    for(int i=1; i<n-1; i++){
        int a = arr[i-1], b = arr[i], c = arr[i+1];

        if(3*b - 2*a == c) continue;
        if(3*b - a == 2*c) continue;

        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}