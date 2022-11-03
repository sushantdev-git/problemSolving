#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool isValid(int x, int y, int n, int m){
    return x>=0 && x< n && y >= 0 && y < m;
}
void solve(){

    int n,m;
    cin>>n>>m;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!isValid(i-1, j+2, n, m) && !isValid(i+1, j+2,n,m) && !isValid(i-1, j-2, n, m) && !isValid(i+1, j-2,n,m) 
            && !isValid(i+2, j+1, n, m) && !isValid(i-2, j+1,n,m) && !isValid(i+2, j-1, n, m) && !isValid(i-2, j-11,n,m)){
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
    }

    cout<<1<<" "<<1<<endl;
    
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