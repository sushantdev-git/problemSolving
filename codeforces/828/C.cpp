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
    char curr; cin>>curr;
    string s; cin>>s;

    vi indx;

    for(int i=0; i<n; i++){
        if(s[i] == 'g') indx.push_back(i);
    }

    int mx = 0;
    for(int i=0; i<n; i++){
        if(s[i] == curr){
            auto it = lower_bound(indx.begin(), indx.end(), i);
            if(it == indx.end()){
                mx = max(mx, n-i + indx[0]);
            }
            else{
                mx = max(mx, *it -i);
            }
        }
    }

    cout<<mx<<endl;
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