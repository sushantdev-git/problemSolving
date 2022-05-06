#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first


void solve(){
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<pair<int,int>> limits;

    int ul= 0, uul = 0, diff = 0;
    int i = 0;
    for(i=0; i<n && k; i++){
        int ch = s[i] - 'a';
        
        
        if(ch <= ul) s[i] = 'a';
        else{
            int d = ch - ul;
            if(d <= k){
                s[i] = 'a';
                ul = ch;
                k-=d;
            }
            else{
                diff = ch - k;
                uul = ch;
                s[i] = 'a' + diff;
                k = 0;
            }
        }

        // cout<<ch<<" "<<ul<<endl;
    }

    while(i < n){
        int ch = s[i] - 'a';
        if(ch <= ul) s[i] = 'a';
        else if(ch <= uul && (s[i] > 'a' + diff)) s[i] = 'a' + diff;
        i++;
    }



    cout<<s<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}