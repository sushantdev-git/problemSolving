#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){
    int n;
    cin>>n;

    vector<int> A(n);

    for(int i=0; i<n; i++)cin>> A[i];

    int x = A[n-1];
    int c = 0;
    for(int i=n-2; i>=0;){
        if(A[i] == x) i--;
        else {
            i = n-1 - (n-1-i)*2;
            c++;
        }
    }

    cout<<c<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}