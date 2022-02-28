#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}
char to_upper(char c) {
    return c < 'a' ? c : c - 32;
}
char to_lower(char c) {
    return c >= 'a' ? c : c + 32;
}

void solve(){
    int n;
    cin>>n;

    vector<int> A(n);
    input_1darr(A,n);

    int c = 0;
    for(int i=1; i<A.size()-1; i++){
        if(A[i-1] < A[i] && A[i] > A[i+1]){
            A[i+1] = max( A[i] , i < n-2 ? A[i+2] : -1);
            c++;
        }
    }

    cout<<c<<endl;
    for(auto i:A) cout<<i<<" ";
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