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

    string s;
    cin>>s;

    set<int> T;

    for(int i=0; i<n; i++){
        if(s[i] == '1') T.insert(i+1);
    }

    cout<<n - T.size()<<endl;
    
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