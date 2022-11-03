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
    int n;
    cin>>n;

    vi a(n), b(n);
    INP(a, n);
    INP(b, n);

    unordered_map<int,int> am, bm;
    
    bool extra = false;
    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            if(bm[a[i]]) {
                bm[a[i]]--;
                am[b[i]]--;
                extra = true;
            }
            else{
                am[a[i]]++;
                bm[b[i]]++;
            }
        }
    }


    cout<<am[0]+am[1]+extra<<endl;
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