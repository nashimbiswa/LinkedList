#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head;
void creatingNode()
{
    int data;
    int choice=1;
    Node *temp;
    head=0;
    while (choice)
    {
        cout<<"Enter a data:\n";
        cin>>data;
        Node *newnode=new Node;
        newnode->data=data;
        newnode->next=nullptr;
        if(head==0)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"Enter 1 to continue:\n";
        cin>>choice;
    }
    
}

void display()
{
    Node *curr;
    curr=head;
    cout<<"Linked list elements are as follows:\n";
    
    if(curr==0)
        cout<<"List is empty:\n";
    else
    {
        while (curr!=0)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    creatingNode();
    display();
    return 0;
}
