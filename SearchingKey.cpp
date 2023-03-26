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



//recursion
auto searchKeyRecursion(Node *head,int key)
{
    if(head==nullptr)
        return -1;
    if(head->data==key)
        return 1;
    else
    {
        int res=searchKeyRecursion(head->next,key);
        if(res==-1)
            return -1;
        else
            return res+1;
    }
}

//Tail Reecursion method
auto searchKeyTailRecursion(Node *head,int key,int count=1)
{
    if(head==nullptr)
        return -1;
    if(head->data==key)
            return count;
    searchKeyTailRecursion(head->next,key,++count);
}

//Iterative search
/*
auto searchKey(Node *head,int key)
{
    if(head==nullptr)
        return -1;
    int count=1;
    while(head!=nullptr)
    {
        if(head->data==key)
            return count;
        ++count;
        head=head->next;
    }
    return -1;
}
*/
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
    cout<<"\nEnter the element to search:\n";
    int key;
    cin>>key;
    cout<<"Element found at:\n"<<searchKeyRecursion(head,key);
    return 0;
}