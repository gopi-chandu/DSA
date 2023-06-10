#include<iostream>
using namespace std;
#include<cstring>
class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
class Q{
    node* head;
    node *tail;
    int count;
    public:
    Q()
    {
        head=NULL;
        tail=NULL;
        count=0;
    }
    //Enque
    void Enque(int data)
    {
        node *newnode=new node(data);
        if(head==NULL && tail==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else if(head!=NULL)
        {
            tail->next=newnode;
            tail=newnode;
        }
        count++;
    }
    //Dequeue
    int Dq()
    {
        if(head==NULL)
        {
            tail=NULL;
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        int a=head->data;
        node *temp=head;
        head=head->next;
        delete temp;
        count--;
        return a;
    }
    //front
    int front()
    {
        int a=head->data;
        return a;
    }
    //size
    int size()
    {
        return count;
    }
    //is empty
    bool isempty()
    {
        if(head==NULL)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    // print
    void print()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    Q q1;
    q1.Enque(1);
    q1.Enque(2);
    q1.Enque(3);
    q1.Enque(4);
    q1.Enque(5);
    q1.print();
    cout<<"Front "<<q1.front()<<endl;
    cout<<"Size "<<q1.size()<<endl;
    cout<<"Dq "<<q1.Dq()<<endl;
    cout<<"Dq "<<q1.Dq()<<endl;
    cout<<"Dq "<<q1.Dq()<<endl;
    cout<<"Dq "<<q1.Dq()<<endl;
    cout<<"Size after deques "<<q1.size()<<endl;

    cout<<"Is empty "<<q1.isempty()<<endl;
}