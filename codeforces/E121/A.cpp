#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        vector<int> mp(26);
        int two_count = 0;
        for(char c:s){
            mp[c-'a']++;
            if(mp[c - 'a'] == 2) two_count++;
        }

        int ind=0;

        for(int i=0; i<26; i++){
            if(mp[i] == 2){
                s[ind] = 'a'+i;
                s[ind+two_count] = 'a'+i;
                ind++;
            }
        }

        for(int i=0; i<26; i++){
            if(mp[i] == 1){
                s[two_count+ind] = 'a'+i;
                ind++;
            }
        }


        cout<<s<<endl;



    }

    return 0;
}