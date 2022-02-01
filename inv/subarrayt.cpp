#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int t){
	int n = arr.size();
	int i=0, j = 0, sum = 0, size = INT_MAX;
	for(; i< n; i++){
		sum+=arr[i];
		while(sum >= t){
			size = min(size, i - j+1);
            sum-=arr[j++];
		}
	}

	return size == INT_MAX ? -1 : size;
}

int main(){
    
    vector<int> arr{1,1,1,1,1};
    cout<<solve(arr, 7)<<endl;
}