#include<cstring>
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    } 
};

class Stack{
    node *head;
    node* tail;
    int count;
    public:
    Stack()
    {
        count=0;
        head=NULL;
    }
   /* void push()
    {
        node *newnode=new node(1);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    int pop()//order of n
    {
        int a=tail->data;
        node *temp=head;
        while(temp->next->data==tail->data)
        {
            tail=temp;
        }
        return a;
    }
    int top()
    {
        int a=tail->data;
        return a;
    }*/
    void push_cn(int a)
    {
        count++;
        node *newnode=new node(a);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    int pop_cn()
    {
        count--;
        int a=head->data;
        head=head->next;
        return a;   
    }
    void print()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int top()
    {
        node *temp=head;
        return temp->data;
    }
    int getsize()
    {
        return count;
    }
    int isempty()
    {
        if(head==NULL)
        {
            return 1;
        }
        return 0;
    }
};

int main() 
{
    Stack s;
    s.push_cn(10);
    s.push_cn(20);
    s.push_cn(30);
    cout<<"After adding"<<endl;
    s.print();
    cout<<"Is empty : "<<s.isempty()<<endl;
    cout<<"Size of Stack"<<endl;
    cout<<s.getsize()<<endl;
    cout<<"Top element"<<endl;
    cout<<s.top()<<endl;
    cout<<"First pop"<<endl;
    cout<<s.pop_cn()<<endl;
    cout<<"after First pop - fullarray"<<endl;
    s.print();
    cout<<"pop"<<endl;
    cout<<s.pop_cn()<<endl;
    cout<<"after 3rd pop - fullarray"<<endl;
    s.print();
    cout<<"Top element"<<endl;
    cout<<s.top()<<endl;
    cout<<"Size of Stack"<<endl;
    cout<<s.getsize()<<endl;
    cout<<"Is empty : "<<s.isempty()<<endl;
    cout<<s.pop_cn()<<endl;
    cout<<"Is empty : "<<s.isempty()<<endl;
    /*s.push(67);
    s.push(70);
    s.push(69);
    s.push(68);
    s.push(67);
     
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;
    cout<<s.isempty()<<endl;  */
}