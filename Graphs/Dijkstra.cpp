#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Dijkstra{
    unordered_map<int, vector<pair<int,int>>> Graph; //adjaceny matrix

    public:
    void insert(int nodeA, int nodeB, int weight){ //in dijkastra we have only positive weight
        Graph[nodeA].push_back({nodeB, weight});
        /*
            {
                1: {{2,3}, {3,4}, {5,2}}
                ......
            }
        */
    }

    int shortestPath(int source, int sink){

        
    }
};