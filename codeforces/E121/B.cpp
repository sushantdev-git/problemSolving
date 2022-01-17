#include<bits/stdc++.h>
using namespace std;

int ii(string &s, int i){
    return s[i] - '0';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int idx = 0,x ,y;
        for(int i=idx; i<s.size()-1; i++){
            x = ii(s, i);
            y = ii(s, i+1);

            if(x+y > 9) idx = i;
        }

        string temp="";
        for(int i=0; i<idx; i++) temp+=s[i];

        x = ii(s,idx);
        y = ii(s,idx+1);
        temp+=to_string(x+y);

        for(int i=idx+2; i<s.size(); i++){
          temp+=s[i];
        }

        cout<<temp<<endl;
    }

    return 0;
}