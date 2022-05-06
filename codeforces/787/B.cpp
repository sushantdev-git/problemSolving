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

    int cnt = 0;
    for(int i=n-2; i>= 0; i--){
        if(arr[i] >= arr[i+1]){
            if(arr[i+1] == 0){
                cout<<-1<<endl;
                return;
            }
            while(arr[i] >= arr[i+1]){
                arr[i]/=2;
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}