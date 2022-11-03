#include<bits/stdc++.h>
using namespace std;

//directives
#define int long long

void solve(){
    
    int n; cin>>n;
    string s; cin>>s;


    string ans;

    int i=1;
    while(i < n){
        if(s[i] == '*'){
            ans+='J';
            while(i < n && s[i] == '*') i++;
            i++;
            continue;
        }
        ans+='W';
        i++;
    }

    cout<<ans<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}