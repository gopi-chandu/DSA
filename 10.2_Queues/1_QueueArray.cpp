#include<iostream>
using namespace std;
#include<cstring>

class Q
{
    int *data;
    int capacity;
    int back;
    //int front;
    public:
    Q()
    {
        data=new int[5];
        capacity=5; 
        //front=0;
        back=0;
    }
    //enqueue
    void enq(int element)
    {
        if(capacity==back)
        {
            int* n=new int[2*capacity];
            for(int  i=0;i<capacity;i++)
            {
                n[i]=data[i];
            }
            delete [] data;
            data=n;
            data[back]=element;
            back++;
            capacity*=2;
        }
        else
        {
            data[back]=element;
            back++;
        }
    }

    //deque
    int deq()
    {
        int a=data[0];
        for(int i=0;i<back;i++)
        {
            data[i]=data[i+1];
        }
        back--;
        return a;
    }
    int size()
    {
        return back;
    }
    int front(){
        int a=data[0];
        return a;
    }
    int isempty()
    {
        if(back==0)
        {
            return 1;
        }
        return 0;
    } 
    void print()
    {
        for(int i=0;i<back;i++)
        {
            cout<<data[i]<<" ";
        }
    }
};
int main()
{
    Q q1;
    q1.enq(1);
    q1.enq(2);
    q1.enq(3);
    q1.enq(4);
    q1.enq(5);
    q1.print();
    cout<<"Front "<<q1.front()<<endl;
    cout<<"Size "<<q1.size()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Size after deques "<<q1.size()<<endl;

    cout<<"Is empty "<<q1.isempty()<<endl;
}