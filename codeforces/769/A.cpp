#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    if(n > 2){
        print("NO");
        return;
    } 
    if(n == 1) {
        print("YES");
        return;
    }

    if(s[0] != s[1]) print("YES");
    else print("NO");


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}