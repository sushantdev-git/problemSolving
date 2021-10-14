#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>> t;
    while(t--){
        int n,k; 
        cin>>n>>k;

        priority_queue<int> q;
        unordered_map<int,int> mp;

        int x;
        for(int i=0; i<k; i++){
            cin>>x;
            q.push(x);
            mp[x]++;
        }
        int cat = 0;
        int save = 0;
        while(cat < n || !q.empty()){
            int m = q.top(); q.pop();
            save++;
            cat+=n - m;
            if(q.empty()) break;
            if(cat >= m || cat >= q.top()) break;

        }

        cout<<save<<endl;
    }
}