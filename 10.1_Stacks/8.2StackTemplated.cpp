
#include<iostream>
using namespace std;
template <typename T>
class node{
    public:
    T data;
    node * next;
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    } 
};
template <typename T>
class Stack{
    node<T>*head;
    node<T>*tail;
    int count;
    public:
    Stack()
    {
        count=0;
        head=NULL;
    }
    void push_cn(T a)
    {
        count++;
        node <T>*newnode=new node<T>(a);
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
    T pop_cn()
    {
        if(isempty)
        {
            count--;
            T a=head->data;
            node<T> *temp=head;
            head=head->next;
            delete temp;
            return a;
        }
        return 0;
    }
    void print()
    {
        node<T>*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int top()
    {
        node<T>*temp=head;
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
    Stack <char>s;
    s.push_cn(65);
    s.push_cn(66);
    s.push_cn(67);
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
    /*Stack <int>s;
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
    cout<<"Is empty : "<<s.isempty()<<endl;*/

}