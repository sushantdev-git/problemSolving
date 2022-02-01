#include<bits/stdc++.h>
using namespace std;

int mindis(int i, int near){
    if(near == 30) return 30;
    else return min(abs(near - i), 26 - abs(near - i));
}
void foundNearest(vector<int> & nearest){
    int near = 30;
    
    for(int i=0; i<26; i++){
        if(!nearest[i]) near = i;
        else nearest[i] = min(nearest[i], mindis(i, near));
    }

    near = 30;
    for(int i=25; i>=0; i--){
        if(!nearest[i]) near = i;
        else nearest[i] = min(nearest[i], mindis(i, near));
    }

    for(auto i: nearest) cout<<i<<" ";
    cout<<endl; 

    //a b c d e f g h i j k l m n o p q r s t u v w x y z
}

int main(){
    int t;
    cin>>t;
    int cases = 1;
    while(t--){
        string s,f;
        cin>>s>>f;
        
        vector<int> nearest(26, 30);
        for(char c:f){
            nearest[c-'a'] = 0;
        }
        
        foundNearest(nearest);
        
        int ans = 0;
        
        for(char c:s){
            ans+=nearest[c - 'a'];
        }
        
        
        cout<<"Case #"<<(cases)<<": "<<ans<<endl;
        cases++;
        
    }
}