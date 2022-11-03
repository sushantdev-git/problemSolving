#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

int canIWin(string &s, int i, int j, string &s1, string &s2, unordered_map<string,int> &dp, bool chance){

    if(i > j) {
        if(s1 == s2) return 0;
        return s1 > s2 ? 1 : -1;
    }

    string key = s1+" "+s2;
    // cout<<key<<endl;
    if(dp.find(key) != dp.end()) return dp[key];

    int ans = -1;
    bool draw = false;

    if(chance){
        s1.push_back(s[i]);
        ans = canIWin(s, i+1, j, s1, s2, dp, !chance);
        draw = draw || ans == 0;
        s1.pop_back();
        if(ans == -1) return dp[key] = 1;
        s1.push_back(s[j]);
        ans = canIWin(s, i, j-1, s1, s2, dp, !chance);
        s1.pop_back();
        draw = draw || ans == 0;
        if(ans == -1) return dp[key] = 1;
    }else{
        s2.push_back(s[i]);
        ans = canIWin(s, i+1, j, s1, s2, dp, !chance);
        s2.pop_back();
        draw = draw || ans == 0;
        if(ans == -1) return dp[key] = 1;
        s2.push_back(s[j]);
        ans = canIWin(s, i, j-1, s1, s2, dp, !chance);
        s2.pop_back();
        draw = draw || ans == 0;
        if(ans == -1) return dp[key] = 1;
    }

    return dp[key] = draw ? 0 : ans;
}



void solve(){
    
    string s;
    cin>>s;

    string s1="", s2 = "";

    unordered_map<string,int> dp;

    int ans = canIWin(s, 0, s.size()-1, s1, s2, dp, true);
    // cout<<ans<<endl;
    if(ans == 1){
        cout<<"Alice"<<endl;
    }
    if(ans == -1){
        cout<<"Bob"<<endl;
    }
    if(ans == 0){
        cout<<"Draw"<<endl;
    }

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