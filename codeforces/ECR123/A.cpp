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
char to_upper(char c) {
    return c < 'a' ? c : c - 32;
}
char to_lower(char c) {
    return c >= 'a' ? c : c + 32;
}

void solve(){
    string s;
    cin>>s;

    set<char> ss;

    bool can = true;
    for(auto c: s){
        if(c == 'R' && ss.find('r') == ss.end()) {
            can = false;
            break;
        }
        else if(c == 'B' && ss.find('b') == ss.end()) {
            can = false;
            break;
        }
        else if(c == 'G' && ss.find('g') == ss.end()) {
            can = false;
            break;
        }
        ss.insert(c);
    }

    if(can) print("YES");
    else print("NO");
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}