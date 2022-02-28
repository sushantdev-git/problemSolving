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

    vector<int> A(n);
    input_1darr(A,n);

    vector<int> mss(n+1);

    vector<int> prefix(n);
    prefix[0] = A[0];

    //creating prefix sum
    for(int i=1; i<n; i++) prefix[i] = prefix[i-1]+A[i];

    //finding maximum subarray sum of each size (1 to n)
    for(int i=1; i<=n; i++){ //i is representing size of subarray
        int mx = prefix[i-1];
        for(int j=i; j < n; j++){
            mx = max(mx, prefix[j] - prefix[j-i]);
        }
        mss[i] = mx;
    }

    vector<int> ans;
    for(int i=0; i<= n;i++){ //updating i elements and finding maximum
        int mx = 0;
        for(int j=1; j<=n; j++){
            if(j < i) mx = max(mx, mss[j]+(j*x));
            else mx = max(mx, mss[j]+(i*x));
        }
        ans.push_back(mx);
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}