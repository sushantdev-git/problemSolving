#include<bits/stdc++.h>
using namespace std;

bool check(string t, string s, string removal){

    string temp = s;

    for(int i=0; i<removal.length() && s.length() > 0; i++){
        string x = "";

        for(int j=0; j<s.length(); j++){
            if(removal[i] == s[j]){
                continue;
            }
            else{
                x+=s[j];
            }
        }
        temp+=x;
        s = x;
    }
    return temp == t;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        string st;
        cin>>st;

        unordered_map<char, int> mp;
        string removal = "";
        for(int i=st.length()-1; i>=0; i--){
            if(mp.find(st[i])==mp.end()){
                removal+=st[i];
                mp[st[i]] = 0;
            }
            mp[st[i]]++;
        }
        reverse(removal.rbegin(), removal.rend());

        int length = 0;

        for(int i=0; i<removal.length();i++){
            length+=mp[removal[i]]/(i+1);
        }

        string prevS = st.substr(0,length);
        
        
        if(check(st, prevS, removal)){
            cout<<prevS<<" "<<removal<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}