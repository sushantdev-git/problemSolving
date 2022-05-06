#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    
    int x, y;
    cin>>x>>y;


    if(y%x != 0){
        cout<<"0 0"<<endl;
    }
    else{
        int k = y/x;

        cout<<1<<" "<<k<<endl;
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