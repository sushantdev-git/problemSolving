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

int minex (vector<bool> &ch){
    for(int i=0; i<26; i++){
        if(!ch[i]) return i;
    }
    return -1;
}

void solve(){
    int n, k;
    cin>>n>>k;


    string s;
    cin>>s;

    map<char,int> mp;
    for(auto &ch: s) mp[ch]++;

    string ans = "";

    int rep = n/k;

    while(k--){
        int take = 0;
        bool nt = true;
        int i;
        for(i=0; i<26 && take < rep; i++){
            if(mp['a'+i] == 0 && nt){
                ans += ('a'+i);
                nt = false;
                take++;
            }
            if(mp['a'+i] != 0){
                take++;
                mp['a'+i]--;
            }
        }

        if(nt) ans += ('a'+i);

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