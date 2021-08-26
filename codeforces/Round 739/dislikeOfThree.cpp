#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int t;
    cin>> t;
    
    while(t--){
        int n;
        cin>>n; 
        
        int i=1;
        int k=1;
        while(i<=n){
            if(k%3 != 0 && k%10 != 3){
                i++;
            }
            k++;
        }
        cout<<--k<<endl;
    }
}