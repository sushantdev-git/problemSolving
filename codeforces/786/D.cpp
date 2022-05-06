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

    int a = INT_MAX, b = INT_MAX;
    for(int i=n-1; i>=0; i--){
        int x = arr[i];
        int y = -1;
        if(i - 1 >= 0){
            y = arr[i-1];
            i--;
        }

        if(x > min(a, b) || y > min(a ,b)){
            cout<<"NO"<<endl;
            return;
        }

        a = min(x, y);
        b = max(x, y);
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