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
        cout<<"Enter the data int the list:\n";
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

//iterative way
void reverseLinkedListI(Node *&head)
{
    Node *prev=0,*nextt,*curr=head;
    cout<<"\n";
    while (curr!=0)
    {
        nextt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
    head=prev;
}

//reversing a linked list recursive
 void reverseLinkedListR(Node *&head,Node *curr,Node *prev)
{
    if(curr==0)
    {
        head=prev;
        return;
    }
    Node* next=curr->next;
        curr->next=prev;
    reverseLinkedListR(head,next,curr);
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


int main(int argc, char const *argv[])
{
    Node *head=0;
    creatingNodes(head);
    cout<<"Linked list are as follows:\n";
    display(head);
    reverseLinkedListR(head,head,nullptr);
    cout<<"\nUpdated Linked list are as follows:\n";
    display(head);
    return 0;
}