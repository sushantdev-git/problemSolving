#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    
    int n; cin>>n;
    string s;
    cin>>s;

    if(n != 5){
        cout<<"NO"<<endl;
        return;
    }

    set<int> st;

    for(auto &ch: s) st.insert(ch);

    string name = "Timur";

    for(auto &ch: name){
        if(st.find(ch) == st.end()){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;


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