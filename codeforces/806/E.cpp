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


    vector<string> mat(n);
    for(int i=0; i<n; i++){
        cin>>mat[i];
    }


    int ans = 0;

    for(int i=0; i<n/2; i++){
        for(int j=i; j<n-i-1; j++){
            int ones = mat[i][j] + mat[j][n-i-1] + mat[n-i-1][n-j-1] + mat[n-j-1][i];
            // cout<<i<<" "<<j<<endl;
            // cout<<j<<" "<<n-i-1<<endl;
            // cout<<n-i-1<<" "<<n-j-1<<endl;
            // cout<<n-j-1<<" "<<i<<endl;

            ones -= 4*'0';
            // cout<<ones<<endl;

            // cout<<"---------------"<<endl;
            ans += min(4-ones, ones);
        }
    }

    cout<<ans<<endl;

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