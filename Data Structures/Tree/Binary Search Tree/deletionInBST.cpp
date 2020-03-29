#include <bits/stdc++.h>
using namespace std;

// structure of a node

struct treeNode
{
    int data;
    treeNode *left, *right;
}*root= NULL;

// function to create a BST

void createBST(int value)
{
    // if the root is null
    if(root == NULL)
    {
        // create node and make that the root
        treeNode *newNode= new treeNode;
        newNode->data= value;
        newNode->left= newNode->right= NULL;
        root= newNode;
        return; // stopping the function to go any further
    }
    // pointer to point to the node where insertion has to take place and previous points to a node before that
    treeNode *pointer= root;
    treeNode *previous= new treeNode;

    // if there's nodes in the BST
    while(pointer != NULL)
    {
        previous= pointer;
        if(value < pointer->data)
            pointer= pointer->left;
        else if(value > pointer->data)
            pointer= pointer->right;
        else
            return; // value is present hence, no need to insert
    } // end of while()

    treeNode *newNode= new treeNode; // newNode to be inserted
    newNode->data= value;
    newNode->left= newNode->right= NULL;
    // deciding where to insert the newNode

    if(value < previous->data)
        previous->left= newNode;
    else
        previous->right= newNode;

} // end of createBST() function

// find the minValue in the sub-tree

treeNode* minValue(treeNode *root)
{
    while(root->left != NULL)
        root= root->left;

    return root;

} // end of minValue()


// function to delete a node from BST

treeNode* deleteFromBST(treeNode* root, int key)
{
    // if root is NULL
    if(root == NULL)
        return root;
    // we're searching for the key first and then we'll delete it.
    else if(key < root->data)
        root->left= deleteFromBST(root->left, key);
    else if(key > root->data)
        root->right= deleteFromBST(root->right, key);
    // if key is found, then we'll delete it
    else
    {
        // Case 1: if the node is a leaf
        if(root->left == NULL && root->right == NULL)
        {
            root= NULL; // nullifying the dangling pointer
            delete(root);
            return root;
        }
        // Case 2: if the node has a single child
        else if(root->left == NULL) // has right child
        {
            treeNode *temp= root;
            root= root->right;
            free(temp);
            return root;
            // parent is not set to the next node of the deleted node.
            // It will get set in the recursive call that's going to happen at 76 or 78 lines of the code.
        }
        else if(root->right == NULL) // has left node
        {
            treeNode *temp= root;
            root= root->left;
            free(temp);
            return root;
        }
        // Case 3: If the node has 2 child
        else
        {
            treeNode *min= minValue(root->right); // find min in right subtree
            root->data= min->data; // swapping the data
            root->right= deleteFromBST(root->right, min->data); // 2 nodes has same value. So, we recursively run it again on RST to delete it.
            return root;
        }
    } // end of else

} // end of deleteFromBST() function

// function to display BST

void Preorder(treeNode* root)
{
    if(root == NULL)
        return;
    else
    {
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
} // end of Preorder() function


int main()
{
    int value;
    cout<<"Enter the elements in the BST: (Zero to end the tree) "<<endl;
    cin>>value;

    while(value != 0)
    {
        createBST(value);
        cin>>value;
    }

    cout<<"\nPreorder of elements are before deletion: ";
    Preorder(root);

    // deletion

    cout<<"\nEnter the node to be deleted: ";
    cin>>value;
    deleteFromBST(root, value);

    cout<<"\nPreorder of elements are before deletion: ";
    Preorder(root);

    return 0;
}
