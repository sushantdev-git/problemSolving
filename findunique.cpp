#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n;
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            cin>>k;
            map[k]++;
        }

        for(auto i: map){
            if(i.second == 1){
                cout<<i.first<<endl;
                break;
            }
        }
    }

    return 0;
}