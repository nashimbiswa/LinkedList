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
void creatingNodesUpto(Node *&head)
{
    Node* temp;
    int arr[]={2,4};
    int i=0;
    while (i<2)
    {
        Node *newnode=new Node(arr[i]);
        if(head==0)
            head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
        ++i;
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

Node* insertAtSortedList(Node *head,int key)
{   

   Node* newnode=new Node(key); 
   if(!head)
   {
        head=newnode;
        return head;
   }
   else if(head->data>=key)
   {
        newnode->next=head;
        head=newnode;
        return head;
   }
   Node* temp=head;
   while(temp->next!=0)
   {    
        if(temp->data<=newnode->data and temp->next->data>=newnode->data)
        {
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }
        temp=temp->next;
   }
   temp->next=newnode;//handling corner case last value
   return head;
    
}
int main(int argc, char const *argv[])
{
    Node *head=0;
    creatingNodesUpto(head);
    cout<<"Linked list are as follows:\n";
    display(head);
    cout<<"\nEnter the element in the sorted linked list:\n";
    int key;
    cin>>key;
    head=insertAtSortedList(head,key);
    cout<<"\nUpdated list:\n";
    display(head);
    return 0;
}