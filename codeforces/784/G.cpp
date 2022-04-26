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

    vector<vector<char>> mat(n, vector<char> (m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>mat[i][j];
    }

    for(int j=0; j<m; j++){
        vector<int> pos;
        int cnt = 0;
        for(int i=0; i<=n; i++){
            if(i == n || mat[i][j] == 'o'){
                for(int k = i-cnt; k < i; k++) pos.push_back(k);
                cnt = 0;
            }
            else if( mat[i][j] == '*') cnt++;
        }

        int k = 0;
        for(int i=0; i<n; i++){
            if(k < pos.size() && i == pos[k]){
                mat[i][j] = '*';
                k++;
            }
            else mat[i][j] = mat[i][j] == 'o' ? mat[i][j] : '.';
        }
    }

    for(auto &v: mat){
        for(auto &c: v) cout<<c<<"";
        cout<<endl;
    }

    cout<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}