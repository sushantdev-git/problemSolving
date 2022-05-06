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

    vector<string> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    if(arr[0][0] == 1){
        cout<<-1<<endl;
        return;
    }

    vector<vector<int>> ans;

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(arr[i][j] != '0'){
                if(i-1 >= 0){
                    ans.push_back({i-1, j, i, j});
                }
                else if(j - 1 >= 0){
                    ans.push_back({i, j-1, i, j});
                }
                else {
                    // cout<<arr[i][j]<<endl;
                    // cout<<i<<" "<<j<<endl;
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto &v: ans){
        for(auto &i: v) cout<<i+1<<" ";
        cout<<endl;
    }
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}   