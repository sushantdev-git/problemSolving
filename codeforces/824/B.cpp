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

    vector<int> arr(n);

    int mn = INT_MAX;   
    for(auto &i: arr){
        cin>>i;
        mn = min(mn, i);
    }

    int cnt = 0;

    for(auto &i: arr){
        if(i >= 2*mn){
            cnt += ceil(i*1.0/(2*mn-1));
            cnt--;
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