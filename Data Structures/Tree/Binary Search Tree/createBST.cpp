#include <iostream>

using namespace std;

// structure of treeNode

struct treeNode
{
    int data;
    treeNode *left, *right;
}*root= NULL;

// function to create BST

void createBST(int value)
{
    // if root is null, then we create a node and make it point to root
    if( root == NULL)
    {
        treeNode *newNode= new treeNode;
        newNode->data= value;
        newNode->left= newNode->right= NULL;
        root= newNode;
        return; // stopping the function as there's no need.
    }
    // creating new node to point to node where insertion has to take place
    treeNode *pointer= root;
    // previous points to one node before which is to be linked to new node
    treeNode *previous= new treeNode;
    while( pointer != NULL)
    {
        previous= pointer;
        if(value < pointer->data)
            pointer= pointer->left; // value is less so it has to be inserted at the left side
        else if(value > pointer->data)
            pointer= pointer->right; // if value is greater so it has to be inserted at the right side
        else // value is equal so doesn't have to be inserted
            return;
    } // end of while()

    // creating new node
    treeNode *newNode= new treeNode;
    newNode->data= value;
    newNode->left= newNode->right= NULL;
    // checking where the newNode has to be inserted
    if(value < previous->data)
        previous->left= newNode;
    else
        previous->right= newNode;

} // end of createBST() function

// function to traverse preorder the binary search tree

void Preorder(treeNode *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

} // end of Preorder()



int main()
{
    int value;
    cout<<"Enter the value that you want to insert: (Zero to end) "<<endl;
    cin>>value;
    while( value!= 0 )
    {
        createBST(value);
        cin>>value;
    }

    cout<<"Preorder Traversal: ";
    Preorder(root);

    return 0;
}
