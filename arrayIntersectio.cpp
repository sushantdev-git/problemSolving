#include<bits/stdc++.h>
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2)
{
    int i=0;
	while (i<size1){
		int j=0;
		while (j<size2){
			if (input1[i]==input2[j]){
				cout<<input1[i]<<" ";
				input2[j]=INT_MIN;
				j++;
				break;
			}
			j++;
		}
		i++;
	}
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n1,n2;
        cin>>n1;
        set<int> set;
        int x;
        for(int i=0; i<n1; i++){
            cin>>x;
            set.insert(x);
        }

        cin>>n2;
        for(int i=0; i<n2; i++){
            cin>>x;
            if(set.find(x) != set.end()) cout<<x<<" ";
        }
    }

    return 0;
}