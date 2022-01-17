#include<bits/stdc++.h>
using namespace std;

bool printA(queue<int> q, int n){
    int i=1;
    while(!q.empty()){
        if(i != q.front()) return false;
        q.pop();
        i++;
    }
    return true;
}

void printB(queue<int> q){
    int i=1,pos;
    while(!q.empty()){
        cout<<q.front()<<" ";
        if(q.front() == 2){
            pos = i;
        }
        i++;
        q.pop();
    }
    cout<<endl;
    cout<<pos<<endl;
}


void riffle(int n, int k){

    queue<int> a;
    queue<int> b;
    bool me = true;

    for(int i=1; i<=n; i++){
        a.push(i);
    }


    int x, i=1;
    while(k--){
        // cout<<"k "<<k<<endl;
        int size=a.size();
        me = true;
        while(size--){
            x = a.front(); a.pop();
            if(me) a.push(x);
            else b.push(x);
            me = !me;
        }
    
        while(!b.empty()) {
            a.push(b.front()); b.pop();
        }

        if(printA(a,n)) cout<<"match at "<<i<<endl;
        printB(a);
        i++;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        riffle(n,k);
    }

    return 0;
}