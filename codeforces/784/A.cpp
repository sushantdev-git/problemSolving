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

    if(n <= 1399) cout<<"Division 4"<<endl;
    else if(n <= 1599) cout<<"Division 3"<<endl;
    else if(n <= 1899) cout<<"Division 2"<<endl;
    else  cout<<"Division 1"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}