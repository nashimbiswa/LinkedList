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

Node *head=nullptr;

//Creating list
void creatingNodes()
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

//Traversing linked list 
void display()
{
    
    if(head==0)
        cout<<"List is empty.\n";
    else
    {
        Node *temp;
        temp=head;
        cout<<"List are as follows:\n";
        while (temp!=0)
        {
           cout<<temp->data<<" ";
           temp=temp->next;
        }
        
    }
}
int main(int argc, char const *argv[])
{
    // creatingNodes();
    display();
    return 0;
}
