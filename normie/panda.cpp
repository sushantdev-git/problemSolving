#include<bits/stdc++.h>
using namespace std;


int setDifference(int A[], int B[], int m, int n){
    set<int> s;
    for(int i=0; i<m; i++){
        s.insert(A[i]);
    }

    int k=0;
    for(int i=0; i<n; i++){
        if(s.find(B[i]) == s.end()) k++;
    }

    return k;
}


// int displayResult(int n, char arr[]){
//     int k=0;
//     for(int i=0; i<n-1; i++){
//         if((arr[i] == '>' && arr[i+1] == '<') ||
//             (arr[i] == '<' && arr[i+1] == '>')
//         ) k++;
//     }
//     return k;
// }

int main(){
    int n,m;
    cin>>n>>m;
    int A[n], B[m];

    for(int i=0; i<n; i++) cin>>A[i];
    for(int i=0; i<m; i++) cin>>B[i];

    cout<<setDifference(A, B, n, m)<<endl;
    return 0;
}