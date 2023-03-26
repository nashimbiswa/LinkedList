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

int lengthOfTheList(Node *head)
{   
    if(head==nullptr)
        return 0;
    else
    {
        Node *curr=head;
        int count=0;
        while (curr!=0)
        {
            ++count;
            curr=curr->next;
        }
        return count;
    }

}
void insertAtPosition(Node *&head,int key,int position)
{
    if(position>lengthOfTheList(head) or head==nullptr)
            cout<<"Can't insert.\n";
    else if(position==1)
    {    
        Node *newnode=new Node(key);
        newnode->next=head;
        head=newnode;
    }
    else
    {
        int count=1;
        Node* temp=head;
        while (count<position-1)
        {
            temp=temp->next;
            ++count;
        }
        Node* newnode=new Node(key);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int main(int argc, char const *argv[])
{
    Node *head=0;
    creatingNodes(head);
    cout<<"Linked list are as follows:\n";
    display(head);
    cout<<"\nList of the length: "<<lengthOfTheList(head)<<endl;
    int key,position;
    cout<<"Enter the key and the position.\n";
    cin>>key>>position;
    insertAtPosition(head,key,position);
    cout<<"\nUpdated list:\n";
    display(head);
    return 0;
}