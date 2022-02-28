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

pair<int,int> reduce(int A, int B){

    for(int i=0; i<32; i++){
        if((A  & (1 << i)) && (B  & (1 << i))){ //both no have a set bit
            B &= (~(1 << i)); //off that bit
        } 
    }
    return {A, B};
}
void solve(){
    int n;
    cin>>n;

    vector<int> A(n);
    for(int i=0; i<n; i++) cin>>A[i];

    for(int i=0; i<n; i++){
        for(int j=i+1; j < n; j++){
            pair<int,int> temp = reduce(A[i], A[j]);
            A[i] = temp.first;
            A[j] = temp.second;
        }
    }

    int sum = 0;
    for(auto i:A) sum+=i;

    cout<<sum<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}