#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

int mod = 1e9+7;

bool isPalindrome(int n){
    string s = to_string(n);
    int i = 0, j = s.size()-1;

    while(i < j){
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

void genPalindrome(vector<int> &palindromes){

    for(int i=1; i<40001; i++){
        if(isPalindrome(i)) palindromes.push_back(i);
    }
}

int cntWays(vector<int> &palindromes, int ind, int sum, vector<vector<int>> &dp){

    if(sum == 0) return 1;
    if(ind >= palindromes.size()) return 0;

    if(dp[sum][ind] != -1) return dp[sum][ind];

    int cnt = 0;
    if(sum >= palindromes[ind]){
        cnt += cntWays(palindromes, ind, sum - palindromes[ind], dp);
        cnt += cntWays(palindromes, ind+1, sum, dp);
    }

    return dp[sum][ind] = cnt%mod;
}

void solve(vector<int> &palindromes, vector<vector<int>> &dp){
    int n;
    cin>>n;

    int ans = cntWays(palindromes, 0, n, dp);
    cout<<ans<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> palindromes;
    genPalindrome(palindromes);

    vector<vector<int>> dp(40001, vector<int> (palindromes.size(), -1));

    int t=1;
    cin>>t;
    while(t--) solve(palindromes, dp);

    return 0;
}