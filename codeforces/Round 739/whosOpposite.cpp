#include<bits/stdc++.h>
using namespace std;
int check(int a, int b, int c){

    int n = 2*abs(a - b);

    int d1 = c + n/2;
    int d2 = c - n/2;

    if(a >n || b> n || c>n){
        return -1;
    }

    if(1<= d1 && d1 <= n){
        return d1;
    }
    if(1<= d2 && d2 <= n){
        return d2;
    }

    return -1;
}
int main(){
    int t;
    cin>>t;
    vector<int> res;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        res.push_back(check(a,b,c));
        
    }

    for(auto i: res){
        cout<<i<<endl;
    }
}