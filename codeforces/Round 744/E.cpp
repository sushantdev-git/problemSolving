#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int x;
        deque<int> d;
        for(int i=0; i<n; i++){
            cin>>x;
            if(d.empty()){
                d.push_back(x);
            }
            else{
                if(x <= d.front()){
                    d.push_front(x);
                }
                else{
                    d.push_back(x);
                }
            }
        }

        while(!d.empty()){
            cout<<d.front()<<" ";
            d.pop_front();
        }
        cout<<endl;
    }
}