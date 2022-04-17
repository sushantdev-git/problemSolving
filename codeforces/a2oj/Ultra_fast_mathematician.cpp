#include<bits/stdc++.h>
using namespace std;


int main(){
    string a,b; 
    cin>>a>>b; 

    string ans = "";
    for(int i=0; i<a.size(); i++){
        ans.push_back(a[i] == b[i] ? '0': '1');
    }
    cout<<ans<<endl;
}