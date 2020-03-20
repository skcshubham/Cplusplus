#include <iostream>
#include <queue>

using namespace std;


// creating structure of a tree

struct treeNode
{
    int data;
    treeNode *left, *right;
}root;

// queue to hold the address of the treeNode

queue <treeNode*> q; // queue of treeNode* type

// create Tree function

void createTree()
{
    int value;
    cout<<"Enter the value in root node: ";
    cin>>value;

    root.data= value;
    root.left= root.right= NULL;
    q.push(&root);

    while( !q.empty() )
    {
        treeNode *pointer= q.front(); // returns front value address to pointer
        q.pop(); // deletes the top or front value

        // code for left child

        cout<<"Enter the left child: ";
        cin>>value;

        // if value isn't -1

        if(value != -1)
        {
            // creating a treeNode
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            pointer->left= newNode;
            q.push(newNode);
        }
        else
            pointer->left= NULL;

        // code for right child

        cout<<"Enter the right child: ";
        cin>>value;

        // if the value isn't -1

        if(value != -1)
        {
            // creating a treeNode
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            pointer->right= newNode;
            q.push(newNode);
        }
        else
            pointer->right= NULL;

    } // end of while()

} // end of createTree()

// preorder traversal of tree

void Preorder(treeNode* p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }
}


int main()
{
    createTree();
    Preorder(&root);
    return 0;
}
