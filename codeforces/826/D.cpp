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

int ans;
int min_ele(vi &arr, int l, int r){
    int mn = INT_MAX;
    for(int i=l; i<=r; i++){
        mn = min(mn, arr[i]);
    }
    return mn;
}

int max_ele(vi &arr, int l, int r){
    int mn = INT_MIN;
    for(int i=l; i<=r; i++){
        mn = max(mn, arr[i]);
    }
    return mn;
}
bool canorder(vi &arr, int l, int mid, int r){
    
    // cout<<l<<" "<<mid<<" "<<r<<endl;
    
    int mnl = min_ele(arr, l, mid);
    int mxl = max_ele(arr, l, mid);

    int mnr = min_ele(arr, mid+1, r);
    int mxr = max_ele(arr, mid+1, r);

    if(mxl > mnr) {
        if(mnl > mxr) {
            // cout<<"rotating"<<endl;
            ans++;
            return true;
        }
        else return false;
    }


    return true;
}

bool divide(vi &arr, int l, int r){
    if(r - l < 1) return true;
    int mid = l + (r-l)/2;

    if(!canorder(arr, l, mid, r)) return false;
    if(!divide(arr, l, mid)) return false;
    if(!divide(arr, mid+1, r)) return false;
    return true;
}


void solve(){
    int n; cin>>n;
    ans = 0;

    vi arr(n);
    INP(arr, n);


    if(divide(arr, 0, n-1)) cout<<ans<<endl;
    else cout<<-1<<endl;
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