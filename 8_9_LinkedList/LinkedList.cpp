#include<cstring>
#include<iostream>
using namespace std;
#include "LinkedListClass.cpp"
void print(node *head)
    {
        while(head!=nullptr)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
node* takeInput()
    {   int data;
        cin>>data;
        node *head=nullptr;
        node *tail=nullptr;
        while(data!=-1)
        {
            node * newNode=new node(data);// holds the current node
            if(head==nullptr)
            {
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=tail->next;
                //or 
                //tail=newNode;
                //both are same
            }
             cin>>data;
            /*else{
                node * temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
            }*/
           
        }
        return head;
    }
node* insertNode(node *head,int i,int data)
{
    node *newnode=new node(data);
    int count=0;
    node *temp=head;
    if(i==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {  
        node *a=temp->next;
        temp->next=newnode;
        newnode->next=a;
    }
    return head;
}
node* deleteNode(node* head,int i)
{   node* temp=head;
    int count=0;
    if(i==0)
    {
        node *a=temp;
        head=head->next;
        delete a; 
        return head; 
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        node* a=temp->next; //a = to be deleted
        node *b=a->next; //elelment after a
        temp->next=b; // joing previous element of a to b and delete a
        delete a;
    }
    return head;
}

node* insertRecursively(node * head,int i,int data) //not working
{
    //base case
    if(i==0)
    {
        node* newnode=new node(data);
        newnode->next=head;
        head=newnode;
        return head;
    }
    //recursion 
    //node * temp=head;
    head=insertRecursively(head->next,i-1,data);
    return head;
}
int length(node * head)
{
    if(head==nullptr)
    {
        return 0;
    }
    int l=1+length(head->next);
    return l;
}
void removeConsecutiveDuplicates(node *head) //not working
{
    node * temp=head;
    while(temp->next!=nullptr && temp!=nullptr)
    {
        node * b=temp->next;
        while(temp->data==b->data)
        {
            node * todel=b;
            node* afterb=b->next;
            temp->next=afterb;
            delete todel;
            b=temp->next->next;
        }
       temp=temp->next;
    }
}
void mid(node * head)
{
    node * slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
void mergeSortedArrays(node * h1,node * h2)
{
    node * head;
    while(h1->data<h2->data)
    {
        head=
        h1=h1->next;
    }
    while(h1->data>h2->data)
    {
        h2=h2->next;
    }
}
int main()
{
    node *head =takeInput();
    print(head);
    //head=insertRecursively(head,9,99);
    //head=insertRecursively(head,0,99);
    //print(head);
    mid(head);
    print(head);
    //cout<<length(head)<<endl;

    /*
    print(head);
    //head=insertNode(head,0,99);
    head=insertNode(head,9,99);
    head=insertNode(head,3,99);
    print(head);
    //head=deleteNode(head,0);
    head=deleteNode(head,3);
    print(head);

    */
    /*
    //Statistically
    node n1(1);
    node *head=&n1;
    node n2(2);
    n1.next=&n2;
    cout<<n1.data<<" "<<n2.data<<endl;

    //Dynamically
    node *n3=new node(10);
    node *head= n3;
    node *n4=new node(20);
    n3->next=n4;
    */
}