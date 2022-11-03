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


    int r = s.size()-1;

    string ans = "";
    while(r >= 0){
        if(s[r] == '0'){
            r--;
            int val = (s[r-1] - '0')*10 + (s[r]-'0');
            // cout<<val<<endl;
            ans.push_back('a'+ val-1);
            r-=2;
        }
        else{
            int val = (s[r]-'0');
            // cout<<val<<endl;
            ans.push_back('a'+val-1);
            r--;
        }
    }


    reverse(ans.begin(), ans.end());

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