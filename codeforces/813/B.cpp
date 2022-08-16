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

    vector<int> arr;
    while(n > 1){
        arr.push_back(n-1);
        arr.push_back(n);
        n-=2;
    }


    if(n){
        arr.push_back(n);
    }

    reverse(arr.begin(),arr.end());
    for(auto &i: arr) cout<<i<<" ";
    cout<<endl;



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