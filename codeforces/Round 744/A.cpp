#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>> s;
        int A = 0, B = 0, C = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'A') A++;
            if(s[i] == 'B') B++;
            if(s[i] == 'C') C++;
        }

        if(B  - A == C){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}