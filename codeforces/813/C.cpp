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

    int n,q; cin>>n>>q;

    vi arr(n);
    INP(arr, n);

    vector<int> pref(n+1);
    vector<int> xx(n+1);

    for(int i=1; i<=n; i++){
        pref[i]+=pref[i-1] + arr[i-1];
        xx[i] = xx[i-1] ^ arr[i-1];
    }

    for(int i=0; i<q; i++){
        int L,R; cin>>L>>R;
        L--, R--;

        int l = L;
        int ans=0, al=L, ar=R;
        int sum = 0, xxor = 0;
        for(int r=L; r<=R; r++){
            sum += arr[r];
            xxor ^= arr[r];


            int rmvVal = (sum - arr[l]) - (xxor ^ arr[l]);
            

            while(l < r && sum - xxor <= rmvVal  && rmvVal > 0){
                sum -= arr[l];
                xxor ^= arr[l];
                l++;
                rmvVal = (sum - arr[l]) - (xxor ^ arr[l]);
            }

            // cout<<l<<" "<<r<<" "<<sum<<" "<<xxor<<endl;

            if(sum - xxor > ans){
                ans = sum - xxor;
                al = l, ar = r;
            }
            else if(sum - xxor == ans){
                if(r-l+1 < ar-al+1){
                    al = l, ar = r;
                }
            }
        }

        cout<<al+1<<" "<<ar+1<<endl;
    }
    
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