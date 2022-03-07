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

    vector<int> A(n);
    input_1darr(A,n);

    vector<int> odd = {0};
    vector<int> even = {0};
    for(int i=0; i<n; i++){
        if(A[i]%2 == 0){
            if(even.back() <= A[i]) even.push_back(A[i]);
            else {
                print("No");
                return;
            }
        }
        else{
            if(odd.back() <= A[i]) odd.push_back(A[i]);
            else {
                print("No");
                return;
            }
        }
    }

    print("Yes");
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}