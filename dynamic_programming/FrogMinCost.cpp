#include<bits/stdc++.h>

using namespace std;

//given stones height and frog can jump max upto 2 stones i+1, i+2
//where i is current index, cost of jumping from current to x stone is
//cost[current] + abs(stoneHeight[current] - stoneHeight[x])
//we have to find min cost to reach the next stone.
int iterative(vector<int> & stonesHeight){

    vector<int> cost(stonesHeight.size(), 0);

    for(int i=1; i<stonesHeight.size();i++){
        int minforCurrentStones = cost[i-1]+abs(stonesHeight[i] - stonesHeight[i-1]);
        if(i-2 != 0){
            minforCurrentStones = min(minforCurrentStones,cost[i-2]+abs(stonesHeight[i] - stonesHeight[i-2]));
        }

        cost[i] = minforCurrentStones;
    }

    for(auto i:cost){
        cout<<i<<" ";
    }
    cout<<endl;
    return cost[cost.size()-1];
}


int main(){
    vector<int> arr = {10,30,40,20};
    cout<<iterative(arr);
    return 0;
}