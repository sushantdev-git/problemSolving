#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

string mins(string &s1, string &s2){
    if(s1.size() == s2.size()){
        return min(s1, s2);
    }
    return s1.size() < s2.size() ? s1 : s2;
}
bool solve(string &s, int sum, int rsum, string &ans){
    // cout<<s<<endl;
    if(sum == rsum){
        // cout<<s<<endl;
        ans = mins(s, ans);
        return true;
    }

    if(sum > rsum) return false;

    int st = s.size() ? s.back()-'0' : 0;
    for(int i=st+1; i<=9; i++){
        s.push_back(i+'0');
        solve(s, sum+i, rsum, ans);
        s.pop_back();
    }

    return false;
}

void solve(){
    int rsum;
    cin>>rsum;

    string ans = "999999999";
    string s = "";
    solve(s, 0, rsum, ans);

    cout<<ans<<endl;
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