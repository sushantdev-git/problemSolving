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

    stack<pair<int,int>> s;
    s.push({A[0],A[0]});
    //5 4 3 2 1
    for(int i=1; i<n; i++){
        
        pair<int,int> curr = {A[i], A[i]};
        while(!s.empty() && curr.first < s.top().second){
            curr = {min(curr.first, s.top().first), max(s.top().second, curr.second)};
            s.pop();
        }
        s.push(curr);
    }

    cout<<s.size()<<endl;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}