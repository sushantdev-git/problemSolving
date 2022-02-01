#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char del){
    int n = s.size();
    s = s.substr(1, n-2);

    string temp = "";
    vector<string> ans;

    for(int i=0; i<n; i++){
        if(s[i] == del) {
            ans.push_back(temp);
            temp ="";
        }
        else temp+=s[i];
    }
    ans.push_back(temp);
    return ans;
}

int to_int(string s){
    bool neg = false;
    int i = 0;
    if(s[0] == '-') {
        i++;
        neg = true;
    }
    int ans = 0;
    
    for(; i<s.size(); i++){
        ans = ans*10+(s[i] - '0');
    }

    return neg ? -ans : ans;
}

vector<int> stringArr_toIntArr(vector<string> arr){
    vector<int> ans;
    for(auto st: arr) ans.push_back(to_int(st));
    return ans;
}