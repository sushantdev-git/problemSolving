#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool find(string &s, char c){
    for(auto &ch: s){
        if(ch == c) return true;
    }
    return false;
}
void solve(){
    
    string s, t;
    cin>>s>>t;

    if(find(t, 'a')){
        if(t.size() > 1)cout<<-1<<endl;
        else cout<<1<<endl;
    }
    else{
        int n = s.size();
        unsigned long long a = 1;
        cout<<(a << n)<<endl;
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