#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// structure of a treeNode

struct treeNode
{
    int data;
    treeNode *left, *right;
}root;

// declaring STL queue to create tree

queue <treeNode*> q;


// function to create a binary tree

void createTree()
{
    int value;

    // pointers that I'll need to serve my soul

    treeNode *ask= new treeNode;
    treeNode *makeChild= new treeNode;

    cout<<"Enter the value in root: ";
    cin>>value;
    root.data= value;
    root.left= root.right= NULL;

    q.push(&root);


    while( !q.empty() ) // runs until the queue is not empty
    {
        // dequeuing the queue and storing the address to pointer p and making it point on that address
        ask= q.front();
        q.pop();

        // For Left Child

        // being here we ask for the value of left child and right child and if it's not -1 we create it
        cout<<"Enter the value of left child: ";
        cin>>value;
        // if value is not -1, we create left child
        if(value != -1)
        {
            treeNode *makeChild= new treeNode;
            // creating a node and then assigning it to 0
            makeChild->data= value;
            makeChild->left= makeChild->right= NULL;
            // setting the left pointer of previous node/parent node to makeChild and pushing address to queue
            ask->left= makeChild;
            q.push(makeChild);
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
            treeNode *makeChild= new treeNode;
            // creating a node and then assigning it to 0
            makeChild->data= value;
            makeChild->left= makeChild->right= NULL;
            // setting the left pointer of previous node/parent node to makeChild and pushing address to queue
            ask->right= makeChild;
            q.push(makeChild);
        }
        else
            ask->right= NULL;
    } // end of while()

} // end of createTree()

// function to iteratively preorder

void Preorder(treeNode* root)
{
    // stack to replace recursion

    stack <treeNode*> s;

    while( root != NULL || !s.empty() ) // looping till root points to null or stack is empty which it initially is.
    {
        if( root != NULL)
        {
            // printing the current node
            cout<<root->data<<" ";
            // pushing address to the stack
            s.push(root);
            // moving to left child
            root= root->left;
        }
        else
        {
            // if root is NULL, we pop an element and make root point to it (backtrack a step)
            root= s.top();
            s.pop();
            // move towards right node or child
            root= root->right;
        }
    } // end of while

} // end of Preorder()


int main()
{
    createTree();
    cout<<"Preorder Traversal : ";
    Preorder(&root);
    return 0;
}
