#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){
    int n;
    cin>>n;

    vector<int> A(n);

    for(int i=0; i<n; i++) cin>>A[i];

    int xx = A[0];
    for(int i=1; i<n; i++) xx^=A[i];

    cout<<xx<<" ";

    xx = 0;
    for(int i=1; i<n; i++) xx^=i;

    cout<<xx<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}