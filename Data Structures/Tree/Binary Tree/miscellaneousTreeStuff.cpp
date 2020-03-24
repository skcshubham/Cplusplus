#include <iostream>
#include <queue>

using namespace std;

// structure of treeNode

struct treeNode
{
    int data;
    treeNode *left, *right;
}root;

// stack to keep track of the address of the tree

queue <treeNode*> q;

// function to create a binary tree

void createTree()
{
    int value;
    cout<<"Enter the value in the root node: ";
    cin>>value;

    root.data= value;
    root.left= root.right= NULL;

    // pushing to stack
    q.push(&root);

    treeNode *pointer= new treeNode;
    while( !q.empty() )
    {
        // pointer points to the address in the stack
        pointer= q.front();
        q.pop();

        // creating left child

        cout<<"Enter the left child of "<<pointer->data<<" : ";
        cin>>value;

        // if value isn't -1, we create node
        if(value != -1)
        {
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            q.push(newNode);
            pointer->left= newNode;
        }
        else
            pointer->left= NULL;

        // creating right child

        cout<<"Enter the right child of "<<pointer->data<<" : ";
        cin>>value;

        // if value isn't -1, we create node
        if(value != -1)
        {
            treeNode *newNode= new treeNode;
            newNode->data= value;
            newNode->left= newNode->right= NULL;
            q.push(newNode);
            pointer->right= newNode;
        }
        else
            pointer->right= NULL;

    } // end of while()

} // end of createTree() function

// counting total nodes in a binary tree

int countNode(treeNode* p)
{
    int x, y;
    // if tree has nodes, count and return
    if(p != NULL)
    {
        x= countNode(p->left);
        y= countNode(p->right);
        return x+y+1;
    }
    return 0;
} // end of countNode()

// counting full nodes

int fullNode(treeNode* p)
{
    int x, y;
    // if tree has nodes
    if(p != NULL)
    {
        x= fullNode(p->left);
        y= fullNode(p->right);
        if(p->left != NULL && p->right != NULL)
            return x+y+1;
        else
            return x+y;
    } // end of if
} // end of fullNode()

// counting number of leaf node

int leafNode(treeNode* p)
{
    int x, y;
    // if tree has nodes
    if(p != NULL)
    {
        x= leafNode(p->left);
        y= leafNode(p->right);
        if(p->left == NULL && p->right == NULL)
            return x+y+1;
        else
            return x+y;
    } // end of if
} // end of leafNode() function


// function to traverse a binary tree

void Preorder(treeNode* p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    } // end of if
} //  end of preorder function

int main()
{
    // creating binary tree
    createTree();
    cout<<"Preorder traversal: ";
    Preorder(&root);
    cout<<"\nTotal Nodes: "<<countNode(&root)<<endl;
    cout<<"Total Full Nodes: "<<fullNode(&root)<<endl;
    cout<<"Total Leaf Nodes: "<<leafNode(&root);

    return 0;
} // end of main()
