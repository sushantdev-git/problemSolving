#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void input_1darr(vector<int> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}

void input_2darr(vector<vector<int>> &arr, int n, int m){
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin>>arr[i][j];
    }
}

void solve(){
    string s;
    cin>>s;

    string ans = "";

    for(int i=0; i<s.size(); i++){
        if(s[i] == '.') ans.push_back('0');
        else if(i < s.size()-1){
            if(s[i+1] == '-') ans.push_back('2');
            else ans.push_back('1');
            i++;
        }
    }

    print(ans);

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}