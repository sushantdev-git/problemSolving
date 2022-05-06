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

    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int mn = INT_MAX;

    for(int i=0; i<n-1; i++){
        int a = arr[i].first;
        int b = arr[i+1].first;

        if(arr[i+1].second - arr[i].second == 1){
            int c = ceil(b/2.0);
            a -= c;
            int c2 = ceil(a/2.0);

            mn = min(mn, c+c2);
        }
        else{
            int c1 = ceil(b/2.0);
            int c2 = ceil(a/2.0);
            mn = min(mn, c1+c2);
        }
    }

    cout<<mn<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}