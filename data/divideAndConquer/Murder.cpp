/*
    Murder
    Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. 
    He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. 
    So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. 
    Calculate the sum of all the numbers written on his notes diary.

    Answer may not fit in integer . You have to take long.

    Input Format:
    First line of input contains an integer T, representing number of test case.
    For each test case, first line of input contains integer N, representing the number of stairs.
    For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.

    Constraints
    T<=10^5
    1<=N<=10^5
    All numbers will be between 0 and 10^9
    Sum of N over all test cases doesn't exceed 5*10^5
    Output Format
    For each test case output one line giving the final sum for each test case.
    
    Sample Input 1:
    1
    5
    1 5 3 6 4
    Sample Output 1:
    15
    Explanation:
    For the first number, the contribution to the sum is 0.
    For the second number, the contribution to the sum is 1.
    For the third number, the contribution to the sum is 1.
    For the fourth number, the contribution to the sum is 9 (1+5+3).
    For the fifth number, the contribution to the sum is 4 (1+3).
    Hence the sum is 15 (0+1+1+9+4).
*/
//we can't do it in n^2 so we will do it in nlong with divide and conquer

#include<bits/stdc++.h>
using namespace std;
    
long long merge(vector<int> &arr, int lo, int mid, int hi){
    
    long long sum = 0, currsum = 0;
    int i = lo, j = mid, k=0;
    vector<int> temp(hi-lo+1);
    
    while(i < mid && j <= hi){
        if(arr[i] < arr[j]){
            currsum+=arr[i];
            temp[k] = arr[i];
            i++;
        }
        else{
            sum+=currsum;
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while(i < mid){
        temp[k] = arr[i];
        k++; i++;
    }
    
    while(j <= hi){
        temp[k] = arr[j];
        k++; j++;
        sum+=currsum;
    }
    
    k=0;
    for(int i=lo; i<=hi; i++, k++){
        arr[i] = temp[k];
    }
    
    return sum;
}

long long divide(vector<int>&arr, int lo, int hi){
    if(hi - lo < 1) return 0;
    int mid = (hi+lo) >> 1;
    
    long long countLeft = divide(arr, lo, mid);
    long long countRight = divide(arr, mid+1, hi);
    long long count = merge(arr, lo, mid+1, hi);
    return countLeft+countRight+count;
}

int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        
        cout<<divide(arr,0, n-1)<<endl;
    }
    return 0;
}