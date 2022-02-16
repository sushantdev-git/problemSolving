#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int a,b;
    cin>>a>>b;
    
    cout<<min(min(a,b), (a+b)/4)<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}