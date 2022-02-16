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
vector<bool> sieve(int n){
    vector<bool> seve(n+1, true);
    seve[0] = false, seve[1] = false;
    for(int i=2; i <= n; i++){
        if(seve[i]) for(int j=2*i; j <= n; j+=i) seve[j] = false;
    }
    return seve;
}

void solve(vector<bool> &seve){
    int n, m;
    cin>>n>>m; 

    for(int i=n+1; i<m; i++){
        if(seve[i]) {
            print("NO");
            return;
        }
    }

    if(seve[m])print("YES");
    else print("NO");


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> seve = sieve(50);
    solve(seve);

    return 0;
}