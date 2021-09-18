#include<bits/stdc++.h>
using namespace std;


//we are given an array we have to find long increasing subsequence in arr
// 50,4,10,8,30,100,2 -> in this array long increasing subsequence is 4,8,30,100
//i.e 4 length
int iterative(vector<int> &sequence){
    vector<int> longestTillThisPoint(sequence.size());
    longestTillThisPoint[0] = 1;
    for(int i = 1; i < sequence.size(); i++){
        int findmax = INT_MIN;
        for(int j = 0; j < i; j++){
            if(sequence[j] <= sequence[i]){
                findmax = max(findmax, longestTillThisPoint[j]);
            }
        }

        longestTillThisPoint[i] = findmax == INT_MIN ? 1 : findmax + 1;
    }

    int maxseq = INT_MIN;
    for(int j = 0; j < sequence.size(); j++){
        cout<<longestTillThisPoint[j]<<" ";
        maxseq = max(maxseq, longestTillThisPoint[j]);
    }
    cout<<endl;
    return maxseq;
}

int main(){
    vector<int> arr = {50,4,10,8,30,100,2};
    cout<<iterative(arr);
    return 0;
}