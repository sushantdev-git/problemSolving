#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first



void calPrefix(vector<vector<int>> &prefix){

    for(int i=1; i<200001; i++){
        for(int j=0; j<32; j++){
            int bit = (i & (1 << j)) == 0 ? 0 : 1;
            prefix[i][j] += prefix[i-1][j] +  bit;
        }
    }

    // for(auto &i: prefix[200000]) cout<<i<<" ";
    // cout<<endl;
}

void solve(vector<vector<int>> &prefix){
    int l,r;
    cin>>l>>r;

    // cout<<endl;
    // for(auto &i: prefix[l]) cout<<i<<" ";
    // cout<<endl;
    // for(auto &i: prefix[r]) cout<<i<<" ";
    // cout<<endl;

    int ans = INT_MAX;
    for(int i=0; i<32; i++){
        ans = min(ans, ((r-l + 1) -  (prefix[r][i] - prefix[l-1][i])));
    }

    cout<<ans<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> prefix(200001, vector<int>(32, 0));

    calPrefix(prefix);
    int t=1;
    cin>>t;
    while(t--) solve(prefix);

    return 0;
}