#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

bool canSolve(map<int,int> mp, int k){

    // cout<<"solving for "<<k<<endl;

    for(int i=1; i<=k; i++){
        auto it = mp.lower_bound(0 - (k-i+1));
        if(it == mp.end()) return false;
        // cout<<"Alice "<<it-> first<<" "<<it ->second<<endl;
        it -> second--;
        if(it -> second == 0) mp.erase(it);

        auto it2 = mp.rbegin();
        if(it2 != mp.rend()){
            // cout<<"Bob "<<it-> first<<" "<<it ->second<<endl;
            it2 -> second--;
            if(it2 -> second == 0) mp.erase(it2 -> first);
        }
    }

    return true;
}

void solve(){
    int n; cin>>n;

    vi arr(n);
    INP(arr, n);

    int l = 0, h = n;

    map<int,int> mp;
    for(auto &i: arr){
        mp[-i]++;
    }

    // for(auto &p: mp){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    while(l <= h){
        int mid = l + (h - l)/2;
        if(canSolve(mp, mid)){
            l = mid+1;
        }
        else h = mid-1;
    }

    cout<<h<<endl;

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