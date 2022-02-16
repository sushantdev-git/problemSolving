#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void input_1darr(vector<int> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}

void input_2darr(vector<vector<int>> &arr, int n, int m){
    int x;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>x;
            arr[i][j] = x%2;
        }
    }
}

bool isValid(int i, int j){
    return i>= 0 && i<3 && j>=0 && j <3;
}

void solve(){

    vector<vector<int>> A(3, vector<int> (3));

    input_2darr(A, 3,3);

    vector<vector<bool>> mat(3, vector<bool>(3, true));


    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(A[i][j]){
                mat[i][j] = !mat[i][j];
                if(isValid(i-1, j)) mat[i-1][j] = !mat[i-1][j];
                if(isValid(i+1, j)) mat[i+1][j] = !mat[i+1][j];
                if(isValid(i, j-1)) mat[i][j-1] = !mat[i][j-1];
                if(isValid(i, j+1)) mat[i][j+1] = !mat[i][j+1];
            }
        }
    }

    for(auto v: mat){
        for(auto i: v)cout<<i;
        cout<<endl;
    }

    


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}