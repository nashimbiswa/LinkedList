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

//Using length of linked list
// T.C=O(n)
void nthNodeFromEndOfTheListL(int position)
{
    if(!head)
        cout<<"List is empty.\n";
    Node* temp=head;
    int length=0;
    while (temp!=0)
    {
        temp=temp->next;
        ++length;
    }
    if(position>length)
        cout<<"Enter a valid position.\n";
    else
    {
        temp=head;
        int i=0;//i=1
        while (i<length-position)//len-pos+1
        {
            temp=temp->next;
            ++i;
        }
         cout<<"Element at the position "<<position<<" is "<<temp->data<<"\n.";
    }    
}

//used two pointer first and second
//first move first pointer to n position ahead
// move first and second pointer with the same speed
// when first reaches the null, the second will point to the required node
// T.C: O(n)
void nthNodeFromEndOfTheListP(int position)
{
    
    if(head==0||position==0)
    {
        cout<<"EERROR\n";
    }
    else
    {
        Node* first, *second;
        first=second=head;
        for(int i=0;i<position;++i)
        {
            //condition for position>length
            if(first==NULL)
            {
                cout<<"Linked list has less number of nodes.\n";
                return;
            }
            first=first->next;
        }
        while (first!=0)
        {
            second=second->next;
            first=first->next;
        }
        cout<<"Element at the position "<<position<<" is "<<second->data<<".\n";
    }
}
int main(int argc, char const *argv[])
{
    creatingNodes();
    display();
    int n;
    cout<<"\nEnter the position of n:\n";
    cin>>n;
    nthNodeFromEndOfTheListP(n);
    nthNodeFromEndOfTheListL(n);
    return 0;

}
