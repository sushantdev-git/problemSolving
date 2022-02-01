#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){
    int n;
    cin>>n;

    vector<int> A(n), B(n);

    for(int i=0; i<n; i++) cin>>A[i];
    for(int i=0; i<n; i++) cin>>B[i];


    int maxA = INT_MIN, maxB = INT_MIN;
    for(int i=0; i<n; i++){
        if(A[i] < B[i]) swap(A[i], B[i]);
        maxA = max(maxA, A[i]);
        maxB = max(maxB, B[i]);
    }


    cout<<(maxA*maxB)<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}