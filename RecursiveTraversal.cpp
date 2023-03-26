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
        cout<<"Eneter the data int the list:\n";
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

int main(int argc, char const *argv[])
{
    Node *head=0;
    creatingNodes(head);
    cout<<"Linked list are as follows:\n";
    display(head);
    return 0;
}
