// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool canfinish(vector<int> &arr, int t){
    int needtime = 0, freetime = 0;
    
    for(auto &i: arr){
        if(i > t){
            needtime += i -t;
        }
        else{
            freetime += (t - i)/2;
        }
    }
    
    return freetime >= needtime;
    
}


void solve(){
    int n,m;
    cin>>n>>m;
    int l=1, r=0;
    vector<int> arr(m);
    for(auto &i: arr) {
        cin>>i;
        i--;
    }

    vector<int> cnt(n, 0);
    for(auto &i: arr) {
        cnt[i]++;
        r = max(r, cnt[i]);
    }

    int ans = INT_MAX;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(canfinish(cnt, mid)){
            r = mid-1;
            ans = min(ans, mid);
        }
        else l = mid+1;
    }
    
    cout<<ans<<endl;
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