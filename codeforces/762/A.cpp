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

    if(s.size() % 2 != 0){
        cout<<"NO"<<endl;
    }
    else{
        int mid = s.size()/2;
        for(int i=0; i<mid; i++){
            if(s[i] != s[i+mid]){
                cout<<"NO"<<endl;
                return;
            }
        }

        cout<<"YES"<<endl;
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