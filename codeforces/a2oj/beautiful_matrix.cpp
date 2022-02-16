#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){

    vector<vector<int>> A(5, vector<int> (5));
    int x,y;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>A[i][j];
            if(A[i][j] == 1){
                x = i, y = j;
            }
        }
    }

    cout<<(abs(2-x)+abs(2-y))<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); solve();

    return 0;
}