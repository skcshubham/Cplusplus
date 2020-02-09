#include <iostream>
using namespace std;

// structure of an array representation of tree

struct TreeStructure
{
    // size or total number of nodes
    int nodes;
    // array used to store tree
    int *array;
}tree;


/*

    Array method of representation is only used for displaying Complete Binary tree because when we store it there is no empty spaces
    between the elements in the array. Array shouldn't have empty spaces between two elements, waste of storage and tough to traverse.

    Concept: We can store a binary tree level wise and when we insert it in an array, the relationship between child and tree still remains
        the same and can be found out easily. We start storing the element from 1 and leave the index 0 to simplify the tree traversal.

        Parent Node: at position i
        Left Child: at position 2i
        Right Child: at position 2i+1

        If we want to find the parent node of children, then parent: floor value of (i/2)
*/

int main()
{
    // giving out disclaimer to the user

    cout<<"\nMake sure you enter a COMPLETE BINARY TREE as other trees cant be stored efficiently in the array implementation!!\n"<<endl;

    // initializing the initial value of treeStructure

    cout<<"Enter the total number of nodes that tree has: ";
    cin>>tree.nodes;
    // because we store tree from index 1 for ease
    tree.array= new int[tree.nodes+1];

    // accepting the value of tree from the user

    cout<<"Enter the value of tree in the order of their level: "<<endl;
    for(int i=1; i<=tree.nodes; i++)
    {
        cin>>tree.array[i];
    }

    // displaying the tree to the user

    cout<<"\nLevel Order Traversal: ";
    for(int i=1; i<=tree.nodes; i++)
    {
        cout<<tree.array[i]<<" ";
    }

    cout<<"\nParent and it's child elements in the tree are: "<<endl;

    // if there's only one node in the tree
    if(tree.nodes == 1)
        cout<<tree.array[1]<<" is the root and has no child"<<endl;
    // if there's multiple nodes in the tree then there's parent child relationship
    else
    {
        // tree.nodes/2 because elements after that are leaves and has no children
        for(int i=1; i<=(tree.nodes/2); i++)
        {
            // displaying left child of the node which is at 2i index
            cout<<"\nLeft Child of "<<tree.array[i]<<" node is "<<tree.array[2*i]<<endl;
            // displaying right child of the node which is at 2i+1 index
            cout<<"\nRight Child of "<<tree.array[i]<<" node is "<<tree.array[2*i+1]<<endl;
        }
    } // end of else


    // displaying the parent of any node or child node

    int child;
    cout<<"\nEnter the element whose parent element you want to know: (-1 to end) ";

    // accepting value of child from user until user enters -1
    while(child != -1)
    {
        // accepting the value of child
        cin>>child;
        // i is loop variable and indexOfChild stores the index of the child
        int i, indexOfChild= 0;

        // traversing and finding the address of the child node
        for(i=1; i<=tree.nodes; i++)
        {
            // if child is equal to any of the element in the tree
            if(tree.array[i] == child)
            {
                indexOfChild= i;
                break;
            }
        }

        /*
            Concept: If we want to find the parent node of children, then parent: floor value of (i/2)
        */

        // element at index 1 is the root element. Hence, it has no parent as it's the root node.
        if(indexOfChild == 1)
            cout<<"It's the root node and hence has no parent."<<endl;
        // if index is greater than 1 and less than the total number of nodes in the array.
        else if(indexOfChild <= tree.nodes && indexOfChild > 1)
            cout<<"Parent of "<<child<<" is "<<tree.array[indexOfChild/2]<<endl;
        // else the element is not present in the tree
        else
            cout<<"Child "<<child<<" is not present in the tree."<<endl;

        // asking user to continuously enter the value of child to check again and again until user enters -1
        cout<<"\nEnter the element whose parent element you want to know: (-1 to end) ";

    } // end of while()

    return 0;
}
