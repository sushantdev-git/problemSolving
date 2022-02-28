#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}
void print(int x) {cout<<x<<endl;}
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

    if(A[n-2] > A[n-1]) {
        print(-1);
    }
    else{
        if(A[n-1] < 0){
            if(is_sorted(A.begin(), A.end())) print(0);
            else print(-1);
        }
        else{
            print(n-2);
            for(int i=1; i<=n-2; i++){
                cout<<i<<" "<<n-1<<" "<<n<<endl;
            }
        }
    }
    nth_element(A.begin(), A.begin()+A.size()/2, A.end());
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}