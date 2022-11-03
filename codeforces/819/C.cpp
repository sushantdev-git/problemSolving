#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    n*=2;

    string s;
    cin>>s;

    vector<int> ps(n,0);
    ps[0] = 1;

    int cmp = 1;
    for(int i=1; i<n; i++){
        ps[i] = ps[i-1] + (s[i] == '(' ? 1 : -1);
        cmp += (s[i] == '(');
    }


    int cnt = 0;
    for(auto &i: ps){
         cnt += i == 0;
    }

    cout<<cmp - (cnt-1)<<endl;
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