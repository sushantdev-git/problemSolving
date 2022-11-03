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

    string s;
    cin>>s;

    vector<int> ans;


    int l=0, r=n-1;


    int sum = 0;

    for(int i=0; i<n; i++){
        if(s[i] == 'L') sum += i;
        else sum += n-1-i;
    }


    int k=1;
    for(int i=1; i<=n; i++){
        while(l <= r && k <= i){
            if(l < n/2 && s[l] == 'R') {
                l++; continue;
            }
            if(r >= n/2 && s[r] == 'L') {
                r--; continue;
            }

            if(n-1-l > r){
                s[l] = 'R';
                sum -= l;
                sum += n-1-l;
                l++;
                k++;
                // cout<<"taking left"<<endl;
            }
            else{
                s[r] = 'L';
                sum -= n-1-r;
                sum += r;
                r--;
                k++;
                // cout<<"taking right"<<endl;
            }
        }
        // cout<<l<<" "<<r<<endl;
        ans.push_back(sum);
    }
    
    // cout<<s<<endl;

    for(auto &i: ans) cout<<i<<" ";
    cout<<endl;


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