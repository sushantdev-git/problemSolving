#include<iostream>
using namespace std;

string revString(string s){
    string ans="";
    string word="";

    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            ans = word +" "+ans;
            word="";
        }
        else{
            word+=s[i];
        }
    }
    ans =word+" "+ans;

    return ans;
}

int main(){
    string s;
    getline(cin,s);
    // cout<<s<<endl;
    cout<<revString(s)<<endl;
}