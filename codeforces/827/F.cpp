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
    int q; cin>>q;

    vi freqS(26,0);
    vi freqT(26,0);
    freqS[0] = 1;
    freqT[0] = 1;

    for(int i=0; i<q; i++){
        int op, rep;
        string s;
        cin>>op>>rep;
        cin>>s;

        for(auto &ch: s){
            if(op == 1) freqS[ch-'a']+=rep;
            else freqT[ch-'a']+=rep;
        }


        int l=0, Tend = 25, Send=25;
        // while(l < 26 && freqS[l] == freqT[l]) l++;
        while(freqT[Tend] == 0) Tend--;
        while(freqS[Send] == 0) Send--;

        if(l < Tend){
            cout<<"YES"<<endl;
        }
        else{
            if(Send == l && freqS[Send] < freqT[Tend]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        
    }
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