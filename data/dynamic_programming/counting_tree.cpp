#include<bits/stdc++.h>
using namespace std;


//given n you have to calculate how many binary trees can be formed with n nodes
//The recurrence relation is pretty sweet.

/*
    Let n = 5;
    1 2 3 4 5
    
    let suppose we choose the node 4
    so in it's left half there can be 4-1 = 3 node
    and in right 5-4 =1 node

    now let's say we can form x binary tree with 3 node (ans is 5)
    and y binary tree with 1 node(and is ofc 1)

    so to know how many binary tree we can make while coosing 4 as root can be given by:
    recurrence relation time:
        we can choose 1 bst from x bst from left so xC1 and 
        similary 1 bst from y bst from right so yC1 (here we are choosing 1 bst from y bst's)

        we can choose root in a single way(because it is a single node)

        so total bst can be formed with root as 4
        is xC1.1.yC1 == x.y //why this
        //if we have 3 balls and 4 bat, so for every ball we can choose 4 bat.
        //hence total combination can be formed will be 3*4

        so relation can be.

        f(i) = f(i-1).f(N-i)  //this is preety sweet.

        //base cases
        if we have 0 or 1 node, there can be only single configuration.

        we have to calculate this recurrence relation for all the nodes.
        from 1 to n
        choose every node.

*/

int recursive(int n, vector<int>&configurations){  


    if(configurations[n] != -1){
        return configurations[n];
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum+= recursive(i-1, configurations)*recursive(n-i, configurations);
    }

    configurations[n] = sum;
    return sum;
}
int main(){

    int n;
    cin>>n;

    vector<int> configurations(n+1,-1);
    configurations[0] = 1;
    configurations[1] = 1;
    cout<<recursive(n, configurations);

}