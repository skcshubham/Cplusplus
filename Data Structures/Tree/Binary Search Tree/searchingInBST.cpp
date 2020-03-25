#include <iostream>

using namespace std;

// structure of a tree

struct treeNode
{
    int data;
    treeNode *left, *right;
}*root= NULL;

// function to create a BST

void createBST(int value)
{
    if(root == NULL)
    {
        treeNode *newNode= new treeNode;
        newNode->data= value;
        newNode->left= newNode->right= NULL;
        root= newNode;
        return;
    }
    treeNode *pointer= root;
    treeNode *previous= new treeNode;
    while(pointer != NULL)
    {
        previous= pointer;
        if(value > pointer->data)
            pointer= pointer->right;
        else if(value < pointer->data)
            pointer= pointer->left;
        else // if value is equal then there's no need to push to BST
            return;
    } // end of while()

    // create new node and link it to the pointer

    treeNode *newNode= new treeNode;
    newNode->data= value;
    newNode->left= newNode->right= NULL;

    // deciding where to attach to BST
    if(value > previous->data)
        previous->right= newNode;
    else
        previous->left= newNode;
} // end of createBST()

// iterative function to search in the BST

treeNode* iterativeSearch(treeNode* root, int key)
{
    if(root == NULL)
        return NULL;
    while(root != NULL)
    {
        if(key == root->data)
            return root;
        else if(key < root->data)
            root= root->left;
        else
            root= root->right;
    } // end of while()
    return NULL; // returns NULL if key is not present

} // end of iterativeSearch function

// recursive function to search

treeNode* recursiveSearch(treeNode* root, int key)
{
    if(root == NULL)
        return NULL;
    if(key == root->data)
        return root;
    else if(key < root->data)
        return recursiveSearch(root->left, key);
    else
        return recursiveSearch(root->right, key);
    // if key is not present
    return NULL;

} // end of recursiveSearch function


int main()
{
    int value;
    cout<<"Enter the value in the BST: (Zero to end)"<<endl;
    cin>>value;
    while(value != 0)
    {
        createBST(value);
        cin>>value;
    }

    // searching in the BST
    int key;
    cout<<"Enter the key that you want to search in BST: ";
    cin>>key;

    treeNode *result= new treeNode;
    result= recursiveSearch(root, key);
    if(result == NULL)
        cout<<"Key is not present!";
    else
        cout<<result->data<<" is present in BST!";

    return 0;
}
