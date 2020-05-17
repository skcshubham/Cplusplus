#include <bits/stdc++.h>
using namespace std;

// function to do BFS on a matrix representation of a graph

void BFS(int G[][7], int beginning, int sizeOfMatrix)
{
    queue <int> q; // queue for BFS
    vector <int> visited (sizeOfMatrix, 0); // vector to store visited nodes
    // starting node from where traversal begins
    int start = beginning;
    // printing the first node
    cout<<start<<" ";
    // setting the node as visited
    visited[start] = 1;
    // pushing the node for exploration
    q.push(start);

    // continuing until the queue is empty
    while( !q.empty() )
    {
        // popping the first element from queue to explore it
        int current = q.front();
        q.pop();
        // exploring the adjacent nodes of the popped element
        for(int i=1; i<=sizeOfMatrix; i++)
        {
            // if the node exists in neighborhood and has not been explored yet
            if(G[current][i] == 1 && visited[i] != 1)
            {
                // pushing the element to queue and setting it as visited
                q.push(i);
                visited[i] = 1;
                cout<<i<<" ";
            }
        }
    }
}

int main()
{

    // matrix representation of graph
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};

    // calling the function and starting traversal from 1
    BFS(G, 1, 7);

    return 0;
}
