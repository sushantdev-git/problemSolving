#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

char cnv(char a, char b){
    if(a == '0' && b == '1') return '1';
    else return '0';
};

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans = s.size();
    for(int i=1; i<s.size(); i++){
        if(s[i] != s[i-1]) ans+=i;
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