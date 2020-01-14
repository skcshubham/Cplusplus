#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linkedList
{
private:
    // head1 and tail1 are pointers for first LL and so on.
    Node *head1, *tail1, *head2, *tail2;
public:
    linkedList()
    {
        head1= tail1= head2= tail2= NULL;
    }

    // function to display the linked list

    void display(Node *head)
    {
        Node *temp= head;
        while(temp != NULL && temp->data != 0)
        {
            cout<<temp->data<<" -> ";
            temp= temp->link;
        }
        cout<<endl;
    }

    // function to create 1st linked list

    Node* createList1(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if the linked list is empty and has no nodes.
        if(head1 == NULL)
        {
            head1= tail1= temp;
            temp= NULL;
        }
        // if linked list has nodes
        else
        {
            tail1->link= temp;
            tail1= temp;
            temp= NULL;
        }
        /* returning the pointer to the head of the first linked list. Yeah, i know that
            the function will be called multiple time to create a linked list but the value
            of head1 will always be the same, ie, the value will be returned same but multiple times.
            That value will come from the if() block of this function.
        */
        return head1;
    }

    // function to create 2nd linked list

    Node* createList2(int value)
    {
        // for comments see the above function. Ain't writing more comments.
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        if(head2 == NULL)
        {
            head2= tail2= temp;
            temp= NULL;
        }
        else
        {
            tail2->link= temp;
            tail2= temp;
            temp= NULL;
        }
        return head2;
    }

    // function to merge two sorted linked list

    Node *mergeList()
    {
        /* dummy head is used to simplify the process. The node which is smaller will be attached to dummyHead and the
        head of that linked list will be moved a node ahead. The process is continued until at least one of the linked list becomes NULL.
        The current node points to the newly inserted node and makes it easy to insert new nodes to the merged linked list. */

        Node *dummyHead= new Node;
        Node *current= dummyHead;
        // the loop will continue to run only until any linked list exhausts, then there's no point is comparing.
        while(head1 != NULL && head2 != NULL)
        {
            // if the value of 1st LL is less than value of 2nd LL
            if(head1->data <= head2->data)
            {
                // the node is attached to the merged LL using current pointer.
                current->link= head1;
                // current pointer is increased as it points to recently inserted node. (tail of merged LL)
                current= head1;
                // head of 1st LL is increased to one node ahead and previous node got inserted.
                head1= head1->link;
            }
            // if the value of the 2nd LL is less than the 1st LL
            else
            {
                // the node is attached to  merged LL
                current->link= head2;
                // value of current increased
                current= head2;
                // head is increased to one node ahead.
                head2= head2->link;
            }
        }
        /* If the linked list is of different sizes, then any one of them will get exhausted
            before the other one. So, the condition below takes care that the linked list which has
            remaining nodes gets attached to the merged LL so that we don't lose the nodes.
        */

        // if first LL gets exhausted
        if(head1 == NULL)
            // current pointer is made point to head2(2nd LL) as it has few nodes remaining
            current->link= head2;
        // else if second LL gets exhausted
        else
            // current pointer is made to point to head1(1st LL) as it has few nodes remaining
            current->link= head1;

        // returning head to the merged linked list
        return dummyHead;
    }
};

int main()
{
    linkedList obj;
    int valueToBeInserted=0;

    // creating and displaying first linked list

    cout<<"Insert the values in first Linked list: (Zero to end)\n";
    cin>>valueToBeInserted;
    Node *list1= new Node;
    while(valueToBeInserted != 0)
    {
        list1= obj.createList1(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"First Linked List: ";
    if(list1->data == 0)
        cout<<"empty\n";
    else
        obj.display(list1);


    // creating and displaying second linked list

    cout<<"Insert the values in Second Linked list: (Zero to end)\n";
    cin>>valueToBeInserted;
    Node *list2= new Node;
    while(valueToBeInserted != 0)
    {
        list2= obj.createList2(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Second Linked List: ";
    if(list2->data == 0)
        cout<<"empty\n";
    else
        obj.display(list2);

    // merging both sorted linked list

    Node *merged= new Node;
    merged= obj.mergeList();
    cout<<"\nMerged Linked List: ";

    /* we're increasing the merged node to one step ahead because merged node is just a pointer and
        if we call display function over merged pointer then 0 will get printed first (default value of empty node)
        and not the value which we have inserted.
    */
    if(merged->data == 0 && merged->link == NULL)
        cout<<"empty";
    else
        obj.display(merged->link);
    cout<<endl;

    return 0;
}
