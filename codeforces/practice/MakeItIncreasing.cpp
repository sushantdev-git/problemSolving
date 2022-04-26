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

    int minMoves = LLONG_MAX;

    //fixing 0 at ith position

    for(int i=0; i<n; i++){
        int j = i-1;
        int mv = 0;
        int lastEle = 0;
        while(j >= 0){
            lastEle += arr[j] - lastEle%arr[j];
            mv += lastEle/arr[j];
            j--;
        }

        lastEle = 0;
        j = i+1;
        while(j < n){
            lastEle += arr[j] - lastEle%arr[j];
            mv += lastEle/arr[j];
            j++;
        }

        minMoves = min(minMoves, mv);
        // cout<<i<<" "<<minMoves<<endl;
        // cout<<endl;

    }

    cout<<minMoves<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}