#include<iostream>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        cout<<abs(min(0,(a- max(b,c)-1)))<<" ";
        cout<<abs(min(0,(b- max(a,c)-1)))<<" ";
        cout<<abs(min(0,(c- max(b,a)-1)))<<endl;
    }
}