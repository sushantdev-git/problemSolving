#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> first, pair<int,int> second){

    if(first.first != second.first) return first.first < second.first;
    else{
        return first.second > second.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        
        int x;
        cin>>x;

        vector<pair<int,int>> pp;
        for(int i=0; i<x; i++){
            
            int n;
            cin>>n;
            vector<int> arr(n);
        
            for(int i=0; i<n; i++){
                cin>>arr[i];
            }
            int init = arr[n-1]+1;

            for(int i=n-2; i>=0; i--){
                init--;
                if(arr[i] >= init) init = arr[i]+1;
                
            }

            
            pp.push_back({init, n});
        }


        sort(pp.begin(), pp.end(), cmp);

        int init = pp[0].first+pp[0].second;
        int temp = pp[0].first;

        for(int i=1; i<pp.size(); i++){

            if(pp[i].first> init){
                temp = temp + (pp[i].first-init);
                init = pp[i].first+pp[i].second;
            } 
            else{
                init = init+pp[i].second;  
            } 
        }

        cout<<temp<<endl;

    }
}