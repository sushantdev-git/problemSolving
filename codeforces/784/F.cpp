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

    int left = arr[0], l = 0, right = arr[n-1], r = n-1;

    int ans = 0;
    while(l < r){
        if(left == right){
            ans = max(ans, l + 1 + n -r);
        }

        if(left <= right){
            l++;
            left += arr[l];
        }
        else if(right < left){
            r--;
            right += arr[r];
        }
    }

    cout<<ans<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}