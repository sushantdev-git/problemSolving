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

    vector<int> even, odd;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x%2 == 0){
            even.push_back(x);
        }
        else odd.push_back(x);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int esum = 0, osum = 0;
    for(int i=1; i<n/2; i++) esum += (even[i] - even[i-1]);
    for(int i=1; i<n/2; i++) osum += (odd[i] - odd[i-1]);

    if((esum + osum) % 4 == 0) cout<<"YES"<<endl;
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