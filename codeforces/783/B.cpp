#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);

    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.rbegin(), arr.rend());
    
    int pos = 0, i = 0;
    pos += 2*arr[i]+1;
    n--, i++;

    // cout<<pos<<" "<<n<<endl;

    while(pos < m && n){
        int left = min(arr[i-1], arr[i]);
        int rem = arr[i] - left;

        pos += rem + arr[i] + 1;
        i++;
        n--;
        // cout<<pos<<" "<<n<<endl;
    }

    if(!n){
        
        if(pos < m){
            cout<<"YES"<<endl;
            return;
        }

        int x = pos - m; //extra required
        // cout<<x<<endl;

        if(x <= arr[0]){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}