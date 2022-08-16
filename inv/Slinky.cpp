#include<bits/stdc++.h>
using namespace std;

int cntBits(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n &= (n-1);
    }

    return cnt;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> arr(n);

        for(auto &i: arr) cin>>i;

        unordered_map<int,int> mp;

        for(auto &s: arr){
            int sz = s.size();
            mp[cntBits(s[0] - 'A')]++;
            mp[cntBits(s[sz-1] - 'A')]++;
        }

        bool ans = true;
        for(auto &p: mp){
            if(p.second % 2 != 0){
                ans = false;
                break;
            }
        }

        if(ans) cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}