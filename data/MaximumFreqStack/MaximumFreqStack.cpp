#include<bits/stdc++.h>
using namespace std;

class FreqStack {
    priority_queue<pair<int,pair<int,int>>> st;
    unordered_map<int,int> mp;
    int pos = 0;
    
    public:
    
    void push(int val) {
        st.push({++mp[val], {pos++, val}});
    }
    
    int pop() {
        int val = st.top().second.second; st.pop();
        mp[val]--;
        return val;
    }
};


int main(){
    int n;
    cin>>n;

    FreqStack ff;
    while(n--){
        string s;
        cin>>s;
        if(s == "push"){
            int a;
            cin>>a;
            ff.push(a);
        }
        else{
            cout<<ff.pop()<<endl;
        }
    }
}