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

    long long sum = 0;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        sum+=x;
        mx = max(mx, x);
    }

    sum-=mx;

    if(sum <= 0 && mx <= 0){
        print(0);
        return;
    }
    

    if(sum >= mx){
        print(1);
    }
    else print(mx - sum);


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}