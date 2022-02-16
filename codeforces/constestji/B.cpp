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
    int n, l;
    cin>>n>>l;

    vector<double> A(n);
    input_1darr(A,n);

    double left = 0, right = l, mid;
    sort(A.begin(),A.end());
    double max_dis = 0;
    for(int i=0; i<A.size()-1; i++){
        max_dis = max(max_dis, A[i+1] - A[i]);
    }

    max_dis/=2;
    int lb = A[0] - 0;
    int up = l - A[A.size()-1];

    max_dis = max(max_dis, double(lb)) ;
    max_dis = max(max_dis, double(up)) ;

    cout<<setprecision(10)<<max_dis<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}