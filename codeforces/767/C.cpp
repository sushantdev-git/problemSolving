#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define ss second
#define ff first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


void solve(){
    int n;
    cin>>n;

    vector<int> A(n);
    unordered_map<int,int> mp;
    set<int> done;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        A[i]=x;
        mp[x]++;
    }

    vector<int> ans;

    int mex = 0;

    for(int i=0; i<n; i++){
        mp[A[i]]--;
        done.insert(A[i]);

        if(A[i] == mex){
            while(done.find(mex) != done.end()) mex++;
            if(mp[mex] == 0){
                ans.push_back(mex);
                mex = 0;
                done.clear();
            }
        }
        else if(mp[mex] == 0){
            ans.push_back(mex);
            mex = 0;
            done.clear();
        }
    }

    cout<<ans.size()<<endl;
    for(auto &i: ans) cout<<i<<" ";
    cout<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}