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


int parse(string &s){
    int cnt = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'X') cnt++;
        else if(s[i] == 'S') cnt*=-10;
        else if(s[i] == 'L') cnt*=10;
    }

    return cnt;
}

void solve(){
    string a,b;
    cin>>a>>b;

    int av = parse(a), bv = parse(b);
    if(av == bv) cout<<"="<<endl;
    else if(av < bv) cout<<"<"<<endl;
    else cout<<">"<<endl;
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