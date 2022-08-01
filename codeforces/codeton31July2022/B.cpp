#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,x;
    cin>>n>>x;


    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int low = arr[0] - x;
    int hi = arr[0] + x;

    // cout<<low<<" "<<hi<<endl;

    int cnt = 0;
    for(int i=1; i<n; i++){
        
        if((arr[i] >= low && arr[i] <= hi) || abs(arr[i] - hi) <= x || abs(arr[i] - low) <= x){
            low = max(low, arr[i]- x);
            hi = min(hi, arr[i] + x);
            // cout<<"in range "<<low<<" "<<hi<<endl;
        }
        else{
            cnt++;
            low = arr[i] - x;
            hi = arr[i] + x;
            // cout<<"change "<<low<<" "<<hi<<endl;
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