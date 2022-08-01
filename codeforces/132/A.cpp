#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int x;
    cin>>x;

    vector<int> arr(4);
    for(int i=1; i<4; i++) cin>>arr[i];

    // for(auto &i: arr) cout<<i<<" ";
    // cout<<endl;

    int cnt = 1;
    while(true){
        // cout<<x<<endl;
        x = arr[x];
        if(x == 0) break;
        cnt++;
    }

    if(cnt == 3){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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