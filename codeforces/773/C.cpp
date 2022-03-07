#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}
void print(int i) {cout<<i<<endl;}

template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}

void solve(){
    int n,x;
    cin>>n>>x;

    map<long long,int> mp;
    vector<long long> arr;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        mp[x]++;
        arr.push_back(x);
    }

    sort(arr.begin(),arr.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        // cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
        if(mp[arr[i]]){
            if(mp[arr[i]*x]) {
                mp[arr[i]*x]--;
            }
            else ans++;
            mp[arr[i]]--;
        }
    }

    cout<<ans<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}