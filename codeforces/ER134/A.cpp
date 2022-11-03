#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    // int n;
    // cin>>n;


    set<char> s;
    for(int i=0; i<4; i++){
        char ch; cin>>ch;
        s.insert(ch);
    }

    if(s.size() == 1) cout<<0<<endl;
    else if(s.size() == 2) cout<<1<<endl;
    else if(s.size() == 3) cout<<2<<endl;
    else cout<<3<<endl;

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