#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define max 6
#define INFINITY 9999



void traversePath(int parent[6] , int i , int startnode){
    vector<int> path;
    while (parent[i] != i){
        path.push_back(i);
        i = parent[i];
        
    }
    
    for (int i : path){
        cout << i << " <- ";
    } 
    cout << startnode;
    cout << "\n"; 

}


void dijkstra(int G[max][max] , int n , int startnode){
    //initialize a vector to store the distances from the starting node
    vector<int> dist(n);

    //initialize an array to backtrack the path that a node arrives in the shortest path 
    int parent[6];
    
    //initialize a priority queue which stores the elements as a pair including ditance and the node

    priority_queue <pair<int , int> , vector <pair <int , int>> , greater <pair <int , int>> > pq;

    //first set distances of all the nodes as infinity in the dist array
    
    for (int i = 0 ; i<n ; i++){
        dist[i] = 1e9;
    }
    
    //then set the starting node of the array as o

    dist[startnode] = 0;
    parent[startnode] = startnode;

    //push the pair which includes the distance and node 
    pq.push({0,startnode});

    //iterate through the queue until it gets empty

    while (!pq.empty()){

        //this priority queue top element is the pair which has the minimum distance
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        //iterate through the adjacency list we created to get neighbour nodes of the current node
        for (int i = 0 ; i<n ; i++){
            if (G[node][i] != 0){
                int edgeWeight = G[node][i];
                int adjNode = i;

                if (dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode] , adjNode});
                }
   
            }
        }
    }

    for (int i = 0 ; i<n ; i++){
        if (i != startnode){
            cout << "Distance of node " << i << " = " << dist[i] << "\n" ;
            traversePath(parent , i , startnode);
        }       
    }

    //calculate average time taken
    int sum = 0;
    for (int i : dist){
        sum += i;
    }
    double average = sum/5;
    cout << "Average time taken : " << average ;
    cout << "\n\n";
}


int main(){
    int G[max][max] = {
        {0 , 10 , 0 , 0 , 15 , 5},
        {10 , 0 , 10 , 30 , 0 , 0},
        {0 , 10 , 0 , 12 , 5 , 0},
        {0 , 30 , 12 , 0 , 0 , 20},
        {0 , 15 , 5 , 0 , 0 , 0},
        {5 , 0 , 0 , 20 , 0 , 0}
    };

    int n = 6;
    int u = 5;

    dijkstra(G , n , u);

    return 0;

}