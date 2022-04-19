// Partition a Linked List around a given value
// Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and finally nodes with value greater than or equal to x. The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.
 
// Example 1:

// Input:
// 1->4->3->2->5->2->3,
// x = 3
// Output:
// 1->2->2->3->3->4->5
// Explanation: 
// Nodes with value less than 3 come first, 
// then equal to 3 and then greater than 3.

// Example 2:

// Input:
// 1->4->2->10 
// x = 3
// Output: 
// 1->2->4->10
// Explanation:
// Nodes with value less than 3 come first,
// then equal to 3 and then greater than 3.
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    // vector<int>smaller,equal,greater;
    Node *curr=head;
    Node *smaller_head=NULL,*greater_head=NULL,*equal_head=NULL;
    Node *smaller_last=NULL,*greater_last=NULL,*equal_last=NULL;
    
    while(curr!=NULL)
    {
        if(curr->data<x)
        {
            if(smaller_head==NULL)
            smaller_head=smaller_last=curr;
            else
            {
                smaller_last->next=curr;
                smaller_last=smaller_last->next;
            }
            
        }
        
        else if(curr->data==x)
        {
             if(equal_head==NULL)
             equal_head=equal_last=curr;
             else
             {
                 equal_last->next=curr;
                 equal_last=equal_last->next;
             }
        }
        else
        {
             if(greater_head==NULL)
             greater_head=greater_last=curr;
             else
             {
                 greater_last->next=curr;
                 greater_last=greater_last->next;
             }
        }
        curr=curr->next;
    }
    if(greater_last!=NULL)
    greater_last->next=NULL;
    //if smaller list is empty
    if(smaller_head==NULL)
    {
        if(equal_head==NULL)
        return greater_head;
        equal_last->next=greater_head;
        return equal_head;
    }
    //if smaller list is not empty and equal list is empty
    if(equal_head==NULL)
    {
        smaller_last->next=greater_head;
        return smaller_head;
    }
    //if both smaller and equal list are non empty
    smaller_last->next=equal_head;
    equal_last->next=greater_head;
    return smaller_head;
    
    
    
}
