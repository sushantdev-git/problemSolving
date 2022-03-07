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
    int n,m;
    cin>>n>>m;

    unordered_map<int,vector<long long>> r;
    unordered_map<int,vector<long long>> c;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            r[x].push_back(i);
            c[x].push_back(j);
        }
    }

    long long ans = 0;
    for(auto &c: r){
        vector<long long> row = c.second;

        sort(row.begin(), row.end());
        int sz = row.size();

        vector<long long> pref(sz);
        pref[sz-1] = row[sz-1];

        for(int i=sz-2; i >= 0; i--){
            pref[i] = pref[i+1]+row[i];
        }

        for(int i=0; i<sz-1; i++){
            ans+= pref[i+1] - (sz - 1 - i)*row[i];
        }
    }

    for(auto &co: c){
        vector<long long> col = co.second;

        sort(col.begin(), col.end());
        int sz = col.size();

        vector<long long> pref(sz);
        pref[sz-1] = col[sz-1];

        for(int i=sz-2; i >= 0; i--){
            pref[i] = pref[i+1]+col[i];
        }

        for(int i=0; i<sz-1; i++){
            ans+= pref[i+1] - (sz - 1 - i)*col[i];
        }
    }

    cout<<ans<<endl;

}

// 1 1 2 2 3 3
// 1 2 4 6 9 12

// A[i+1] - A[i] + A[i+2] - A[i] + A[i+3] - A[i] 
// (A[i+1]+ A[i+2] + A[i+3] + .. + A[i+n-1]) - (n-1-i)*A[i] 
// (pref[n-1] - perf[i]) - (n-i-1)*A[i]



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}