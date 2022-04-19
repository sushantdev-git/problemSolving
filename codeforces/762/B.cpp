#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    int i=1;
    int cnt = 0;
    set<int> s;
    while(i*i <= n){
        int square = i*i;
        int cube = i*i*i;
        if(s.find(square) == s.end()){
            s.insert(square);
            cnt++;
        }

        if(cube <= n && s.find(cube) == s.end()){
            s.insert(cube);
            cnt++;
        }

        i++;
    }


    cout<<cnt<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}