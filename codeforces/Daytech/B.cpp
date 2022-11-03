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
    int l, r;
    cin>>l>>r;
 
    int st=sqrt(l);
    int e=sqrt(r);
    int count=3*(e-(st+1));
    if(l%st==0)
        count++;
    int sqr=(st+1)*(st+1);
    count+=((sqr-1)/st-l/st)+1;
    count+=(r/e)-e;
    cout<<count<<endl;
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