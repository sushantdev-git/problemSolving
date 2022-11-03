#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> first;
    vector<int> second(4, 100);
    vector<int> third(second);
    vector<int> fourth(third);
    int arr[] = {16,20,22,23};

    vector<int> fifth(arr, arr + sizeof(arr)/sizeof(int));
}