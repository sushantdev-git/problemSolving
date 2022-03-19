#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        unordered_map<int,int> mp;
        int n,x;
        cin>>n;
        int c = 0;
        while(n--){
            cin>>x;
            mp[x]++;
            if(mp[x] == 2) mp[-x]++;
        }
        c+=mp.size();
        cout<<c<<endl;
    }
}