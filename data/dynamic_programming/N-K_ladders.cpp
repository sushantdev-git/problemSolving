#include<iostream>
#include<vector>

using namespace std;

int recursive(int n, int k, vector<int>& counter){

    if(n==1){
        counter[n] =1;
        return 1;
    }

    int i=1;
    int sum = 0;
    while(n-i >= 0 && i<=k){
        if(counter[n-i] != -1){
            sum+=counter[n-i];
        }
        else{
            counter[n-i] = recursive(n-i, k, counter);
            sum+=counter[n-i];
        }
        i++;
    }

    counter[n] = sum;
    return counter[n];

}


int bottomUpIterative(int n, int k){
    if(k == 0) return 0;
    if (n <= 1) return 1;
    vector<int> arr(n+1,-1);
    arr[0] = 1;
    arr[1] = 1;
    int sum = 1;

    for(int i = 2; i <= n; i++) {
        if(i<=k){
            sum+=arr[i-1];
            arr[i] = sum;
        }
        else{
            arr[i] = 2*arr[i-1] - arr[i-k-1];
        }
    }

    return arr[n];
}


int main(){
    int N = 10;
    int k = 5;
    vector<int> counter(N+1,-1);
    counter[0] = 1;
    recursive(N, k,counter);
    cout<<counter[N]<<endl;

    cout<<bottomUpIterative(N,k)<<endl;

}