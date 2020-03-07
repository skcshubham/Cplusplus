#include <bits/stdc++.h>
using namespace std;

/*  ******** Tree Node ********      */

// structure of a node of the tree

struct treeNode
{
    // data to store value
    int data;
    // left and right to store left and right subtree
    treeNode *left, *right;
};

treeNode *root= new treeNode;

/*   **************  Queue functions  ***************   */

// structure of a queue (FIFO)

struct QueueNode
{
    // address of tree has to be pushed hence data holds structure of treeNode
    treeNode *data;
    QueueNode *link;
}*front, *back;

// adding from the end of the linked list in O(1) time

void enqueue(treeNode *value)
{
    QueueNode *node= new QueueNode;
    node->data= value;
    node->link= NULL;
    if(front == NULL)
        front= back= node;
    else
    {
        // linking new node to end of the linked list using back pointer
        back->link= node;
        // making the back pointer point to the new end node of the list i.e. node
        back= node;
    }
} // end of enqueue()

// deleting from the beginning of the linked list in O(1) time as well

treeNode* dequeue()
{
    QueueNode *temp;
    if(front == NULL)
        return NULL;
    else
    {
        temp= front;
        front= front->link;
        // returning the node which was dequeued
        return temp->data;
    }
} // end of dequeue()


/*
    Concept: In linked list, we maintain a head pointer but here in tree, we maintain a root pointer. We are going to generate the tree level by level.
            We need a queue data structure to store the address of the nodes and ask at each node whether it has right or left child or not. We maintain
            a queue to make sure that we go to each node and ask if the element exists or not. If it exists, then we again create a node and then,
            push the address of that node to the queue and pop an address again from the queue. (check Bari to remove confusion lecture. 268)
*/


 // functions for tree

int isEmpty()
{
    return (front == back);
}

void Preorder(treeNode* p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void createBinaryTree()
{
    // extra pointers that we need
    treeNode *ask= new treeNode;
    treeNode *makeChild= new treeNode;
    treeNode *mainRoot= new treeNode;


    int value;
    // creating root pointer
    cout<<"Enter the value in the root node: ";
    cin>>value;

    root->data= value;
    root->left= root->right= NULL;

    // enqueue the address of root into the queue
    enqueue(root);

    // looping through the nodes and pushing it to he queue

    while( isEmpty() ) // runs until the queue is not empty
    {
        // dequeuing the queue and storing the address to pointer p and making it point on that address
        ask= dequeue();

        // For Left Child

        // being here we ask for the value of left child and right child and if it's not -1 we create it
        cout<<"Enter the value of left child: ";
        cin>>value;
        // if value is not -1, we create left child
        if(value != -1)
        {
            // creating a node and then assigning it to 0
            makeChild->data= value;
            makeChild->left= makeChild->right= 0;
            // setting the left pointer of previous node/parent node to makeChild and pushing address to queue
            ask->left= makeChild;
            enqueue(makeChild);
        }
        else
            ask->left= NULL;


        // For Right Child


        // being here we ask for the value of left child and right child and if it's not -1 we create it
        cout<<"Enter the value of right child: ";
        cin>>value;
        // if value is not -1, we create left child
        if(value != -1)
        {
            // creating a node and then assigning it to 0
            makeChild->data= value;
            makeChild->left= makeChild->right= 0;
            // setting the left pointer of previous node/parent node to makeChild and pushing address to queue
            ask->right= makeChild;
            enqueue(makeChild);
        }
        else
            ask->right= NULL;

    } // end of while()
} // end of createBinaryTree() function


int main()
{
    int data= 0, node= 0;

    createBinaryTree();

    // preorder traversal

    Preorder(root);

    return 0;
}
