#include <bits/stdc++.h>
using namespace std;

// array to keep track of nodes that have been visited
vector <int> visited(8, 0);

void DFS(int G[][7], int start, int sizeOfMatrix)
{
    // if vertex is not visited then we'll do something else we'll leave
    if(visited[start] == 0)
    {
        // displaying the vertex
        cout<<start<<" ";
        // marking the vertex as visited
        visited[start] = 1;
        // looping through it's adjacent vertexes
        for(int i=1; i<=sizeOfMatrix; i++)
        {
            // if the node is adjacent to the vertex "start"
            if(G[start][i] == 1)
                // calling the function recursively from the new adjacent vertex
                DFS(G, i, sizeOfMatrix);
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
    DFS(G, 1, 7);

    return 0;
}
