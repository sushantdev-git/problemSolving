// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    // Write C++ code here
    vector<vector<int>> arr = {{5,5},{6,3},{3,6}};
    
    auto it = upper_bound(arr.begin(), arr.end(), arr[0]);
    if(it != arr.end()){
        cout<<it - arr.begin()<<endl;
    }
    return 0;
}