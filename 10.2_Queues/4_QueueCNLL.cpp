#include<iostream>
using namespace std;
#include<cstring>
template <typename T>
class node{
    public:
    T data;
    node* next;
    node(T data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
template <typename T>
class Q{
    node<T> *head;
    node<T> *tail;
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
        node <T>*newnode=new node<T>(data);
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
    T Dq()
    {
        if(head==NULL)
        {
            tail=NULL;
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        T a=head->data;
        node <T>*temp=head;
        head=head->next;
        delete temp;
        count--;
        return a;
    }
    //front
    T front()
    {
        T a=head->data;
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
        node <T>*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    Q<int> q1;
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
    cout<<"Dq "<<q1.Dq()<<endl;
    cout<<"Dq "<<q1.Dq()<<endl;
    cout<<"Size after deques "<<q1.size()<<endl;

    cout<<"Is empty "<<q1.isempty()<<endl;
}