#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    
    string s;
    cin>>s;

    int i=0;
    char c = s[0];

    while(i < s.size()){
        int j = i+1;
        while(j < s.size() && s[j] == s[i]) j++;
        if((j - i) < 2){
            cout<<"NO"<<endl;
            return;
        }
        i = j;
    }

    cout<<"YES"<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}