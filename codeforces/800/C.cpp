#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int sz;
    cin>>sz;

    vector<int> arr(sz);
    for(int i=0; i<sz; i++) cin>>arr[i];

    int i=sz-1;
    while(i >= 0 && arr[i] == 0) i--;
    if(i >= 0 && arr[i] > 0) {
        cout<<"No"<<endl;
        return;
    }

    int next = abs(arr[i--]), prev;

    while(i >= 0){
        prev = next - arr[i];
        next = prev;
        if(i != 0 && prev == 0) {
            cout<<"No"<<endl;
            return;
        }
        i--;
    }
    
    cout<<"Yes"<<endl;
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