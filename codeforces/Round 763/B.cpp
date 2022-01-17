#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,a,b;
        cin>>n;

        set<pair<int,int>> s;
        vector<pair<int,int>> arr;

        for(int i=0; i<n; i++){
            cin>>a>>b;
            s.insert({a,b});
            arr.push_back({a,b});
        }

        for(auto p:arr){
            if(p.first == p.second){
                cout<<p.first<<" "<<p.first<<" "<<p.first<<endl;
            }
            else{
                for(int i=p.first ; i<= p.second; i++){
                    if(s.find({p.first, i-1}) != s.end()
                        || s.find({i+1, p.second}) != s.end()
                    ){
                        cout<<p.first<<" "<<p.second<<" "<<i<<endl;
                        break;
                    }
                }
            }
        }
    }
}