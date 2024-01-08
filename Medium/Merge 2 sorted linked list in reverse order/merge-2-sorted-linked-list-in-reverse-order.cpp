//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* temp=head;
        while(head!=NULL)
        {
            temp=temp->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
        
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* head=NULL;
        Node* temp=head;
        while(node1!=NULL && node2!=NULL)
        {
            if(node1->data<=node2->data)
            {
                if(head==NULL)
                {
                    head=temp=node1;
                }
                else
                {
                    temp->next=node1;
                    temp=temp->next;
                }
                node1=node1->next;
                
            }
            else
            {
                if(head==NULL)
                {
                    head=temp=node2;
                }
                else
                {
                    temp->next=node2;
                    temp=temp->next;
                }
                node2=node2->next;
            }
        }
        if(node1!=NULL)
        {
            if(head==NULL) head=node1;
            else temp->next=node1;
        }
        if(node2!=NULL)
        {
            if(head==NULL) head=node2;
            else temp->next=node2;
        }
        
        return reverse(head);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends