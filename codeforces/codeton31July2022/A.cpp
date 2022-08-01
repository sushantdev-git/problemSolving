#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m;
    cin>>n>>m;

    string s1, s2;
    cin>>s1>>s2;


    int i = s1.size()-1;
    int j = s2.size()-1;

    // cout<<i<<" "<<j<<endl;


    while(i >= 0 && j > 0){
        if(s1[i] != s2[j]){
            cout<<"NO"<<endl;
            return;
        }
        i--;
        j--;
    }

    while(i >= 0){
        if(s1[i] == s2[j]){
            cout<<"YES"<<endl;
            return;
        }
        i--;
    }

    cout<<"NO"<<endl;

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