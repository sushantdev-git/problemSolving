#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    int child;
    int cnt;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        child = 0;
        cnt = 1;
    }
};


int getCnt(Node * root){
    if(!root) return 0;
    return root -> cnt + root -> child;
}

Node * insert(Node * root, int val){
    if(!root) return new Node(val);
    if(val < root -> val) root -> left = insert(root -> left, val);
    if(val > root -> val) root -> right = insert(root -> right, val);
    else root -> cnt ++;

    int tc = getCnt(root -> left) + getCnt(root -> right);

    root -> child = tc;
    return root;
}


int count(Node * root, int val){
    if(!root) return 0;
    if(val < root -> val){
        int cnt =  root -> cnt + getCnt(root -> right);
        return count(root -> left, val) + cnt;
    }
    if(val > root -> val) return count(root -> right, val);

    return getCnt(root -> right);
}

int main(){

    int n,k;
    cin>>n>>k;

    Node * root = NULL;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int sum = 0;

    // root = insert(root, arr[0]);


    for(int i=1; i<n-1; i++){
        if(arr[i] <= arr[i+1]){
            int x = count(root, arr[i]);
            cout<<arr[i]<<" "<<x<<endl;
            sum += x;
        }
        // root = insert(root, arr[i]);
    }

    cout<<sum<<endl;

}