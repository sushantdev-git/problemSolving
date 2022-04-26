#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    string s;
    cin>>s;

    int n = s.size();

    stack<char> st;

    for(int i=0; i<n-1; i++){
        char ch = s[i];
        if(st.empty()) st.push(ch);
        else if(st.top() == 'A' && ch == 'B') st.pop();
        else st.push(ch);
    }

    if(s[n-1] == 'B'){

        if(st.size() == 0) {
            cout<<"NO"<<endl;
            return;
        }
        while(st.size() && st.top() == 'A') st.pop();

        if(st.size() == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}