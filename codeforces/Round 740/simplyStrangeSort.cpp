#include<bits/stdc++.h>
using namespace std;

void f(vector<int> &arr, int i, int n){
    if(i > n){
        return;
    }
    if( arr[i] > arr[i+1]){
        swap(arr[i], arr[i+1]);
    }

    return f(arr, i+2, n);
}
int bubblesort(vector<int> arr){

    int count = 0;
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    int n = arr.size();
    int i=1;
    while(arr != sorted) {
        if(i%2 == 0){
            f(arr, 1, n-1);
        }
        else{
            f(arr, 0, n-2);
        }
        i++;
        count++;
    }


    return count;
}

int main(){

    int t;
    cin>>t;
    vector<int> res;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        res.push_back(bubblesort(arr));
    }

    for(auto i: res){
        cout<<i<<endl;
    }
    return 0;
}