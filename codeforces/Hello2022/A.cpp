#include<bits/stdc++.h>
using namespace std;

void createBoard(int n, int k){
    vector<string> ans(n, string(n,'.'));

    for(int i=0; i<n && k > 0; i+=2){
        ans[i][i] = 'R';
        k--;
    }


    for(auto str: ans){
        for(auto ch: str){
            cout<<ch;
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n < k*2-1){
            cout<<-1<<endl;
            continue;
        };
        createBoard(n,k);
    }

    return 0;
}