#include<bits/stdc++.h>

using namespace std;

void generateans(priority_queue<pair<int,int>> &pq){

    int ans = 0;
    string s="";
    while(!pq.empty()){
        pair<int,int> p1 = pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }

        pair<int,int> p2 = pq.top();
        pq.pop();

        ans++;
        for(int i=0 ; i<min(1, p2.first); i++){
            s+=to_string(p1.second)+" "+to_string(p2.second)+"\n";
        }

        if(p2.first -1 > 0) pq.push({--p2.first, p2.second});
        if(p1.first -1 > 0) pq.push({--p1.first,p1.second});
    }
    cout<<ans<<endl;
    cout<<s;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        priority_queue<pair<int,int>> pq;
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x != 0) pq.push({x,i+1});
        }

        generateans(pq);
    }
}