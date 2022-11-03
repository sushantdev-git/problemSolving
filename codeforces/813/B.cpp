#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    bool flip = false;
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        int v1 = s[i] - '0', v2 = s[i+1] - '0';

        if(!flip && v1 > v2){
            cnt++;
            flip = !flip;
        }

        if(flip && v2 > v1){
            cnt++;
            flip = !flip;
        }
    }

    cout<<cnt<<endl;
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