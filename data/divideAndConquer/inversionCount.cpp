/*
    Inversion Count

    For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
    An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
    A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

    1. 'ARR[i] > 'ARR[j]' 
    2. 'i' < 'j'

    Where 'i' and 'j' denote the indices ranging from [0, 'N').
    Input format :
    The first line of input contains an integer 'N', denoting the size of the array.

    The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
    Output format :
    Print a single line containing a single integer that denotes the total count of inversions in the input array.
    Note:
    You are not required to print anything, it has been already taken care of. Just implement the given function.  
    Constraints :
    1 <= N <= 10^5 
    1 <= ARR[i] <= 10^9

    Where 'ARR[i]' denotes the array element at 'ith' index.

    Time Limit: 1 sec
    Sample Input 1 :
    3
    3 2 1
    Sample Output 1 :
    3
    Explanation of Sample Output 1:
    We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
    Sample Input 2 :
    5
    2 5 1 3 4
    Sample Output 2 :
    4
    Explanation of Sample Output 1:
    We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/

#include<bits/stdc++.h>
long long c = 0;
// 1 4 5 - 2 3 6
void merge(long long *arr, int s1, int s2, int n1, int n2){
    long long a1[n1];
    long long a2[n2];

    for(int x = 0; x < n1; x++) a1[x] = arr[s1+x];
    for(int x = 0; x < n2; x++) a2[x] = arr[s2+x];
    
    int k=s1,i=0, j=0;
    while(i < n1 && j < n2){
        if(a1[i] <= a2[j]){
            arr[k] = a1[i];
            i++;
        }
        else{
            arr[k] = a2[j];
            c+= n1-i;
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = a1[i];
        i++; k++;
    }
    
    while(j < n2){
        arr[k] = a2[j];
        j++; k++;
    }
    
    
}

void divide(long long *arr, int lo, int hi){
    if(hi - lo < 1) return;
    int mid = lo + (hi - lo)/2;
    divide(arr, lo, mid);
    divide(arr, mid+1, hi);
    int n1 = mid-lo+1;
    int n2 = hi - mid;
    merge(arr, lo, mid+1, n1, n2);
}

long long getInversions(long long *arr, int n){
    divide(arr, 0, n-1);
    return c;
}