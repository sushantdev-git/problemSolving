#include<bits/stdc++.h>
using namespace std;


bool compareInterval(vector<int> &v1, vector<int> &v2)
{
    if(v1[0] > v2[0]) return 1;
    else if(v1[1] < v2[1]) return 1;
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;


        vector<vector<int>> pairs;
        vector<vector<int>> size;

        int l,r,c;

        for(int i=0; i<n; i++){
            cin>>l>>r>>c;
            pairs.push_back({l,r,c});
            size.push_back({r-l+1, c, i});
        }

        set<int> have;

        sort(size.begin(), size.end(),compareInterval);

        int money = 0;

        for(auto v:size){
            l=pairs[v[2]][1];
            r=pairs[v[2]][2];

            
        }



    }

    return 0;
}