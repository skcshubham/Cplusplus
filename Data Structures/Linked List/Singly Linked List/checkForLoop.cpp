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
    Node *head, *tail;
public:
    linkedList()
    {
        head= tail= NULL;
    }

    // function to check if the linked list has loop

    /*  To check if list has loop, we use two pointers; one pointer moves by one step each time and the other one moves by
        two steps. If the linked list has loop, then at some point these both pointers will meet each other and if the
        linked list is linear (has no loop), then the pointer moving faster will become NULL. If list has loop, both these
        pointers go round and round until they meet and will never become NULL.
    */

    void isLoop()
    {
        // slow pointer moves by one node, fast pointer moves two nodes at a time
        Node *slow, *fast;
        // loop boolean is used just to make sure that we know if loop exists. (used like flag)
        bool loop= false;
        // both pointer initially points at head
        slow= fast= head;
        // the loop should stop if any pointer points to NULL. (linear list)
        while(fast != NULL || slow != NULL)
        {
            // slow moves a node ahead
            slow= slow->link;
            // fast moves two nodes ahead
            fast= fast->link->link;
            // if both pointers meet, loop exists else there is no loop
            if(fast == slow)
                loop= true;
        }
        if(loop == false)
            cout<<"There is no LOOP !!";
        else
            cout<<"There is LOOP !!";
    } // end of isLoop()

};

int main()
{
    linkedList obj;
    obj.isLoop();
    /*  Haven't created a linked list because its very tough to create a linked list which has loop.
        that is, the last node doesn't points to NULL but points to some other node in the linked list.
    */
    return 0;
}
