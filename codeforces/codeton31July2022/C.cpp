#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> arr(m);
    for(auto &i: arr) cin>>i;


    sort(arr.begin(), arr.end());

    int z = arr[0];
    int y = n - arr[m-1];

    arr.push_back(arr[m-1] + z + y);

    vector<int> mat;
    for(int i=1; i<=m; i++){
        mat.push_back(arr[i] - arr[i-1] - 1);
    }

    // for(auto &i: arr) cout<<i<<" ";
    // cout<<endl;

    sort(mat.rbegin(), mat.rend());


    int x = 0;

    int ans = 0;
    for(int i=0; i<mat.size(); i++){
        int save = max(0LL, mat[i] - x);
        // cout<<save<<endl;
        if(save){
            ans+=save == 1 ? 1 : save - 1;
            x += save - 1 == 1 ? 2 : 4;
        }
    }

    // cout<<"---"<<ans<<endl;

    cout<<n - ans<<endl;
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