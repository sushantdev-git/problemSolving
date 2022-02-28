#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}
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

#define sort(A) sort(A.begin(),A.end())
#define fo(i,a,b) for(int i=a; i<=b; i++)

int mod = 1e9+7;

unordered_map<int,bool> mp; 
//mp this no from any no belonging to previous 2^(i-2) to 2^(i-1) if curr set is 2^(i-1) to 2^(i)
unordered_map<long long,bool> arrEle;

bool can(int n){
    if(mp.find(n) != mp.end()) return mp[n];
    if(arrEle[n]) return true;
    if(n == 0) return false;
    if(n%4 != 0 and n%2 == 0)return false;
    bool ans = false;

    if(n%4 == 0) ans |= can(n/4);
    if(n%2 == 1) ans |= can((n-1)/2);
    return mp[n] = ans;
}

void solve(){
    int n,p,i;
    cin>>n>>p;

    mp.clear();
    arrEle.clear();

    vector<int> A(n);
    fo(i,0,n-1){
        cin>>A[i];
        arrEle[A[i]] = true;
    }


    vector<long long> dp(p+1,0);
    sort(A);

    fo(i,1,p){
        if(i <= 30){
            for(int j=0; j<A.size() && A[j] < (1 << i); j++){
                if(A[j] >= (1 << (i-1))){ //if the no belong to 2^(i-1) to 2(i)
                    bool canPutInSet = true;
                    if(A[j]%4 == 0  && can(A[j]/4)) canPutInSet = false;
                    if(A[j]%2 == 1  && can((A[j]-1)/2)) canPutInSet = false;
                    if(canPutInSet) dp[i]++;
                }
            }
        }
        if(i >= 1) dp[i] = (dp[i]+dp[i-1])%mod;
        if(i >= 2) dp[i] = (dp[i]+dp[i-2])%mod;
    }
    long ans = 0;
    fo(i,1,p){
        ans = (ans+dp[i])%mod;
    }

    cout<<ans<<endl;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}