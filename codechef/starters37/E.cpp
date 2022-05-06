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


    stack<pair<char,int>> st;
    st.push({'0', 0});

    for(int i=0; i<s.size(); i++){
        char ch = s[i];
        if(st.top().first == '(' && ch == ')') st.pop();
        else st.push({ch, i});
    }

    if(st.size() == 1){
        cout<<0<<" "<<1<<endl;
        return;
    }

    int cnt = 0;
    cout<<st.size() - 1<<" ";

    int last = s.size()-1;

    while(st.size()){
        if(last - st.top().second  > 1) cnt++;
        last = st.top().second;
        st.pop();
    }


    cout<<cnt<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}