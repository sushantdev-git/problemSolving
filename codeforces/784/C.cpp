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
    for(int i=0; i<n; i++) cin>>arr[i];

    int rem = arr[0]%2;
    for(int i=2; i<n; i+=2){
        if(arr[i]%2 != rem){
            cout<<"NO"<<endl;
            return;
        }
    }

    rem = arr[1]%2;
    for(int i=3; i<n; i+=2){
        if(arr[i] % 2 != rem){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}