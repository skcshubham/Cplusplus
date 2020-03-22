#include <iostream>
#include <queue>

using namespace std;

// structure of a tree

struct treeNode
{
    int data;
    treeNode *left, *right;
}root;

// queue to traverse level order

queue <treeNode*> q;

// function to create binary tree

void createTree()
{
    int value;
    cout<<"Enter the value in the root node: ";
    cin>>value;

    root.data= value;
    root.left= root.right= NULL;

    treeNode *pointer= new treeNode;

    // pushing address to the queue

    q.push(&root);

    while( !q.empty() )
    {
        // making pointer point to address in the queue
        pointer= q.front();
        q.pop();

        // left child

        cout<<"Enter the value in left child node: ";
        cin>>value;
        if( value != -1 )
        {
            // creating node, putting value and pushing it to the queue
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            q.push(newNode);
            pointer->left= newNode;
        }
        else
            pointer->left= NULL;

        // right node

        cout<<"Enter the value in right child node: ";
        cin>>value;
        if( value != -1 )
        {
            // creating node, putting value and pushing it to the queue
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            q.push(newNode);
            pointer->right= newNode;
        }
        else
            pointer->right= NULL;

    } // end of while()

} // end of createTree()

// function to inorder traverse the tree

void levelorder(treeNode* root)
{
    treeNode *pointer= new treeNode;
    // printing the data
    cout<<root->data<<" ";
    // pushing address to queue
    q.push(root);

    while( !q.empty() ) // until queue is empty
    {
        // popping queue and making pointer point to it
        pointer= q.front();
        q.pop();
        // if the tree has left child, the push and print it.
        if(pointer->left)
        {
            // printing and pushing it to queue
            cout<<pointer->left->data<<" ";
            q.push(pointer->left);
        }
        // if the tree has right child, the push and print it
        if(pointer->right)
        {
            // printing and pushing it
            cout<<pointer->right->data<<" ";
            q.push(pointer->right);
        }
    } // end of while
} // end of level order


int main()
{
    createTree();
    cout<<"Iterative Inorder traversal: ";
    levelorder(&root);
    return 0;
}
