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
    int n;
    cin>>n;

    vector<long long> A(n);
    input_1darr(A,n);

    sort(A.begin(), A.end());

    long long blue = A[0] , red = 0;
    bool can = false;
    for(int i=n-1; i>n/2; i--){
        blue +=A[n-i];
        red +=A[i];
        if(red > blue) {
            can = true;
            break;
        }
    }

    if(can) print("YES");
    else print("NO");

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}