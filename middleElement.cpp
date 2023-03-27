#include<bits/stdc++.h>
using namespace std;

struct Node
{   
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=nullptr;
    }
};

// reference to the first pointer (struct node *& first)
void creatingNodes(Node *&head)
{
    Node *temp;
    int choice=1;
    while (choice)
    {
        int data;
        cout<<"Enter the data in the list:\n";
        cin>>data;
        Node *newnode=new Node(data);
        if(head==0)
            head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"Enter 1 to continue:\n";
        cin>>choice;
    }
}
void display(Node *head)
{
    if(head==nullptr)
        return;
    else
    {
        cout<<head->data<<" ";
        display(head->next);
    }
}

//Naive solution
// T.C: O(n)
void middleElementN(Node *head)
{
    if(!head)   return;
    Node* temp=head;
    int count=0;
    while (temp!=0)
    {
        temp=temp->next;
        ++count;
    }
    temp=head;
    for(int i=0;i<count/2;++i)
    {
        temp=temp->next;
    }
    cout<<"\nMiddle element is "<<temp->data<<"."<<endl;
}

//Efficent Solution
// Using fast and slow pointers
// slow moves 1 at a time fast moves 2 position at a time.
void middleElementE(Node *head)
{
    if(!head)   return;
    Node*slow,*fast;
    slow=fast=head;
    // fast!=nullptr for even size
    // fast->next!=0 for odd size
    while (fast!=nullptr and fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"\nMiddle element is "<<slow->data<<".";
}
int main(int argc, char const *argv[])
{
    Node *head=0;
    creatingNodes(head);
    cout<<"Linked list are as follows:\n";
    display(head);
    // cout<<"\nUpdated list:\n";
    // display(head);
    middleElementE(head);
    return 0;
}