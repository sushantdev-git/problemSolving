#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){

    vector<int> r1(2,0), r2(2,0);
    cin>>r1[0]>>r1[1];
    cin>>r2[0]>>r2[1];

    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

    if(r1[0] == 1) ans1++;
    if(r2[0] == 1 || r2[1] == 1 || r1[1] == 1) ans1++;

    if(r1[1] == 1) ans2++;
    if( r1[0] == 1 || r2[0] == 1 || r2[1] == 1) ans2++;

    if(r2[0] == 1) ans3++;
    if(r1[0] == 1|| r1[1] == 1|| r2[1] == 1 ) ans3++;

    if(r2[1] == 1) ans4++;
    if(r1[1] == 1|| r1[0] == 1 || r2[0] == 1 ) ans4++;

    cout<<min(ans4, min(ans3,min(ans1, ans2)))<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}