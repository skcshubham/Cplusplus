#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// structure of a binary tree

struct treeNode
{
    int data;
    treeNode *left, *right;
}root;

// queue to store address to create a binary tree

queue <treeNode*> q;

// function to create a binary tree

void createTree()
{
    int value;

    cout<<"Enter the value in root node: ";
    cin>>value;

    root.data= value;
    root.left= root.right= NULL;

    // pushing root address in queue
    q.push(&root);

    while( !q.empty() )
    {
        // pointer pops the queue and make pointer points to it
        treeNode *pointer= q.front();
        q.pop();


        // left child

        ccout<<"Enter the left child of "<<pointer->data<<" : ";
        cin>>value;

        if(value != -1)
        {
            // creating a new node
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            // making the left pointer point to the newNode
            pointer->left= newNode;
            // pushing the address of newNode to the queue
            q.push(newNode);
        }
        else
            pointer->left= NULL;

        // right child

        cout<<"Enter the right child of "<<pointer->data<<" : ";
        cin>>value;

        if(value != -1)
        {
            // creating a new node
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            // making the right pointer point to the newNode
            pointer->right= newNode;
            // pushing the address of newNode to the queue
            q.push(newNode);
        }
        else
            pointer->right= NULL;

    } // end of while()

} // end of createTree()

// function to iteratively inorder the binary tree

void Inorder(treeNode* root)
{
    // stack to replace recursion

    stack <treeNode*> s;

    while( root != NULL || !s.empty() )
    {
        if( root != NULL )
        {
            // pushing root to stack
            s.push(root);
            // moving left
            root= root->left;
        }
        else
        {
            // popping stack and pointing root to it's address (kinda backtrack a step)
            root= s.top();
            s.pop();
            // printing the data of root
            cout<<root->data<<" ";
            // moving right
            root= root->right;
        }
    } // end of while()

} // end of Inorder()


int main()
{
    createTree();
    cout<<"Inorder traversal: ";
    Inorder(&root);
    return 0;
}
