#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>> n;

        double x = sqrt(n);
        int y = sqrt(n);

        if(x == y){
            cout<<y<<" "<<1<<endl;
        }
        else{
            if(n <= pow(y,2)+1+y){
                cout<<(n - pow(y,2))<<" "<<y+1<<endl;
            }
            else{
                cout<<y+1<<" "<<(y+1 - (n - (pow(y,2)+1+y)))<<endl;
            }
        }
    }
}