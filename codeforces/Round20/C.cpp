#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

int getNo(int a, int b){
    for(int i=1; i<9; i++){
        if(i != a && i != b) return i;
    }
    return 1;
}

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);

    int l = -1, r = -1;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(i > 0 && arr[i] == arr[i-1]){
            if(l == -1) l = i+1;
            r = i+1;
        }
    }

    if(l == r) cout<<0<<endl;
    else cout<<max(1LL, r - l -1)<<endl;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}   