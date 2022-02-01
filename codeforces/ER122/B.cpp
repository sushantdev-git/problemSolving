#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){
    string s;
    cin>>s;

    int z = 0, o = 0;

    int mx = 0;
    for(auto c : s){
        if(c == '1') o++;
        else z++;

        if(z > 0 && o > 0 && z != o){
            mx = max(mx, min(z,o));
        }

    }

    cout<<mx<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}