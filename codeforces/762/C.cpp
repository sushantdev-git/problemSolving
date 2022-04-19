#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int a,b; 
    cin>>a>>b;
    if(b < a) {
        cout<<-1<<endl;
        return;
    }
    string s1 = to_string(a);
    string s2 = to_string(b);

    int i = s1.size()-1, j = s2.size()-1;

    string ans = "";

    while(i > -1 || j > -1){
        int x;
        if(i > -1 && j > -1){
            if(s1[i] <= s2[j]){
                x = s2[j] - s1[i];
                i--;
                j--;
            }
            else{
                if(j - 1 <= -1){
                    cout<<-1<<endl;
                    return;
                }
                x = (s2[j-1] - '0')*10 + (s2[j] - '0') - (s1[i] - '0');
                i--;
                j-=2;
            }
        }
        else{
            if(i < j){
                x = s2[j] - '0';
                j--;
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }

        if(x > 9 || x < 0){
            cout<<-1<<endl;
            return;
        }
        
        // cout<<x<<" "<<i<<" "<<j<<endl;
        ans = to_string(x) + ans;
    }

    i = 0;
    while(ans[i] == '0') i++;

    if(i == ans.size())cout<<0<<endl;
    for(; i<ans.size(); i++) cout<<ans[i];
    cout<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}