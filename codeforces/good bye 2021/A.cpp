#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        unordered_map<int,int> mp;
        int n,x;
        cin>>n;

        while(n--){
            cin>>x;
            mp[x]++;
        }
        int count =0;
        set<int> s;
        for(auto p: mp){
            if(s.find(p.first) != s.end()) continue;
            if(p.first == 0) count++;
            else if(p.second == 1) count++;
            else {
                count+=2;
                s.insert(-p.first);
            }
        }

        cout<<count<<endl;
    }
}