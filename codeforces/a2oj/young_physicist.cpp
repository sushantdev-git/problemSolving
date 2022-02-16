#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    int f1 = 0,f2 = 0,f3 = 0,x,y,z;
    for(int i=0; i<n; i++){
        cin>>x>>y>>z;
        f1+=x;
        f2+=y;
        f3+=z;
    }

    if(f1 == f2 && f1 == f3 && f1 == 0) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}