#include<bits/stdc++.h>
using namespace std;

//given an array of elements we have to find maximum sum of non adjcent elements
//in 6,10, 12, 7,9,14 maxsum will be 6+12+14
int iterative(vector<int> &elements){

    if(elements.size() == 0) return 0;
    if(elements.size() == 1) return elements[0];
    if(elements.size() <= 2) return max(elements[0], elements[1]);

    vector<int> maxsum(elements.size());
    maxsum [0] = elements[0];
    maxsum [1] = max(elements[0], elements[1]);
    for(int i = 2; i < elements.size(); i++){
        maxsum[i] = max(maxsum[i-1], maxsum[i-2]+elements[i]); 
        
    }

    return maxsum[elements.size()-1];
}

int main(){
    vector<int> arr = {6,10, 12, 7,9,14};
    cout<<iterative(arr);
    return 0;
}