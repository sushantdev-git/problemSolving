#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, vector<int>& b, int n){

    unordered_map<int,int> a_m;
    unordered_map<int,int> b_m;

    for(int i=0; i<n; i++){
        a_m[a[i]] = i;
    }

    for(int i=0; i<n; i++){
        b_m[b[i]] = i;
    }


    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());


    for(int i=0; i<n; i++){
        if(b[i] > a[i]){
            return a_m[a[i]]+b_m[b[i]];
        }
    }

    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n),b(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        for(int i=0; i<n; i++){
            cin>>b[i];
        }



        cout<<solve(a,b,n)<<endl;
    }
}