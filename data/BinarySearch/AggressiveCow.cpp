/*
    Aggressive Cows Problem
    Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
    His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, 
    FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. 
    What is the largest minimum distance?

    Input Format:
    The first line of input contains number of test cases, which will be denoted by the symbol t. 
    In the following lines, the t test cases are written.
    The first line of each of the test cases contain two space separated integers:
     N and C. The following line contains N space separated integers, where the ith integer denote the position of ith stall. 
    It is given that sum of N over all the test cases doesn't exceed 1000, 000.   

    Output Format:
    As described in the problem statement, the first and only line of output will print the largest minimum distance possible. 
    The output for each test case will be printed on a separate line. 

    Sample Input 1:
    2
    11 3
    15 5 2 4 17 16 12 8 19 18 11 
    15 13
    20 8 16 3 13 9 11 10 15 17 18 14 1 2 5 
    
    Sample Output 1:
    8
    1
*/

#include<bits/stdc++.h>
using namespace std;
int nextBarn(vector<long long> &arr, long long num){
    return *lower_bound(arr.begin(), arr.end(), num);
}

bool canPlace(vector<long long>&arr, long long dis, int c, int n){
    //placing cows dis apart
    long long start = arr[0];
    c--;
    while(start <= arr[n-1] && c){
        int temp = nextBarn(arr, start+dis);
        // cout<<start<<" "<<temp<<endl;
        if(start >= temp || temp > arr[n-1]) break;
        start = temp;
        c--;
    }
    return c==0;
}

int findMin(vector<long long> &arr, int c, int n){
    long long lo = 1, hi = arr[n-1]-arr[0], mid = 0;
    
    while(lo <= hi){
        mid = lo + (hi - lo) /2;
        // cout<<lo<<" "<<hi<<" "<<mid<<endl;
        if(canPlace(arr, mid, c, n)){
            // cout<<"place at "<<mid<<endl;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    
    return hi;
}

int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        
        int n,c;
        cin>>n>>c;
        vector<long long> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(), arr.end());
        
        // for(auto i: arr) cout<<i<<" ";
        // cout<<endl;

        cout<<findMin(arr, c, n)<<endl;
        // cout<<canPlace(arr, 5, c, n)<<endl;
        
    }
    return 0;
}