#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;



void solve(){
    int n, q;
    cin>>n>>q;

    vi arr(n);
    INP(arr, n);

    vi query(q);
    INP(query, q);


    vector<int> need(n);
    need[0] = arr[0];
    int mx = arr[0];

    for(int i=1; i<n; i++){
        mx = max(mx, arr[i]);
        need[i] = mx;
    }

    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }

    // cout<<"all process"<<endl;

    for(auto &x: query){
        int lo = 0, hi = n-1;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(need[mid] <= x){
                ans = max(ans, mid);
                lo = mid+1;
            }
            else hi = mid-1;
        }

        cout<<(ans == -1 ? 0 : arr[ans])<<" ";
    }
    cout<<endl;

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