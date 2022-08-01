#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first


bool check(string &str){
    stack<char> s;
    deque<char> qs;

    for(auto &ch: str){
        if(ch == '?') qs.push_back(ch);
        else if(s.size() == 0 && ch == ')') qs.push_back(ch);
        else if(s.size() == 0 && ch == '(') s.push(ch);
        else if(ch == ')') s.pop();
        else if(ch == '(') s.push(ch);
        else qs.push_back(ch);
    } 

    while(s.size()){
        if(qs.size() - s.size() >= 2) return false;
        qs.pop_front();
        s.pop();
    }
    
    int x = 0;
    while(qs.size()){
        if(qs.front() == '?') x++;
        else x = 0;
        qs.pop_front();
        if(x > 2) return false;
    }

    return true;
}

void solve(){
    string s;
    cin>>s;

    if(check(s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}