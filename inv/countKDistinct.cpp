#include<bits/stdc++.h>
using namespace std;


int main(){

    set<int> bset;

    int an, bn; cin>>an>>bn;

    vector<int> a(an);

    for(auto &i: a) cin>>i;
    
    for(int i=0; i<bn; i++){
        int x; cin>>x;
        bset.insert(x);
    }

    int k; cin>>k;

    unordered_map<int,int> mp;
    int left = 0, right = 0, ans = INT_MAX;

    while(right < an){

        if(bset.find(a[right]) != bset.end()){
            mp[a[right]]++;
        }

        while(mp.size() >= k){

            if(mp.size() >= k) ans = min(ans, right-left+1);

            if(bset.find(a[left]) != bset.end()){
                mp[a[left]]--;
            }

            if(mp[a[left]] == 0) mp.erase(a[left]);

            left++;
        }

        right++;
    }

    cout<<ans<<endl;
    
}