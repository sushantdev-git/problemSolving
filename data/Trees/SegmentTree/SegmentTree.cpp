#include<bits/stdc++.h>
using namespace std;

/*
    segment tree is used to calculat sum of part of subarray from (l, r) in logn time.
    functions of tree:
        set(index, value)
        getSum(segLeft, segRight)

    to make segement tree we need an array of len of power of 2
        if len in not power of two we suff 0 to segRight of array
    
    height of segement tree is log2(n)

    we manage the tree in a single array like we do in case of heap
    root at i and child at 2*i+1, 2*i+2;

    each node in segemnt tree sum of it's segLeft and segRight child.

*/



class SegmentTree{

    vector<long long> sum;
    int size = 1;

    public:

    void init(int n){
        while(size < n) size*=2;
        sum.resize(2*size,0);
    }

    void set(int index, int val, int node, int segLeft, int segRight){

        // cout<<segLeft<<" "<<segRight<<endl;
        if(segRight - segLeft == 1) {
            sum[node] = val;
            // cout<<"inserted"<<endl;
            return;
        }

        int mid = (segLeft+segRight)/2;

        if(index < mid) set(index, val, 2*node+1, segLeft, mid);
        else set(index, val, 2*node+2, mid, segRight);

        sum[node] = sum[2*node+1] + sum[2*node+2];
    }

    void set(int index, int val){
        //this function is used to set val at index
        set(index, val, 0, 0, size);
    }

    long long get(int left, int right, int node, int segLeft, int segRight){
        if(segLeft >=right || segRight <=left) return 0; //if given segment and curr segment is not overlapping;
        if(segLeft >= left && segRight <=right) return sum[node]; //if the curr segment is completely inside the given segment

        //is segment is partially overlapping then we can call on right and left part of tree
        int mid = segLeft+(segRight-segLeft)/2;

        long long sum1 = get(left,right, 2*node+1, segLeft, mid);
        long long sum2 = get(left,right, 2*node+2, mid, segRight);

        return sum1+sum2;
    }

    long long get(int l, int r){
        return get(l, r, 0, 0, size);
    }

    void print(){
        for(auto &i: sum) cout<<i<<" ";
        cout<<endl;
    }

};

int main(){
    SegmentTree s;
    int n,m;
    cin>>n>>m;

    s.init(n);
    for(int i=0; i<n; i++){
        int val; cin>>val;
        s.set(i, val);
    }

    while(m--){
        int operation, a,b ;
        cin>>operation>>a>>b;

        if(operation == 1) s.set(a,b);
        else cout<<s.get(a,b)<<endl;
    }

    // s.print();
}