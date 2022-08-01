// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b, int ind, int suma, int sumb, int h, unordered_map<string, int> &dp){
    if(ind >= a.size()) {
        if(sumb && ((suma/sumb) == h)){
            return suma;
        }
        return 0;
    }
    
    string key = to_string(ind) + " " + to_string(suma);
    
    if(dp.find(key) != dp.end()) return dp[key];
    
    int ans = 0;
    ans = solve(a, b, ind+1, suma+a[ind], sumb+b[ind], h, dp);
    ans = max(ans, solve(a, b, ind+1, suma, sumb, h, dp));
    // cout<<key<<" "<<ans<<endl;
    return dp[key] = ans;
}


int main() {
    int n;
    cin>>n;
    
    int h; cin>>h;
    vector<int> a(n), b(n);
    for(auto &i: a) cin>>i;
    for(auto &i: b) cin>>i;
    
    unordered_map<string,int> dp;
    int ans = solve(a,b, 0, 0, 0, h, dp);
    cout<<ans<<endl;
    return 0;
}