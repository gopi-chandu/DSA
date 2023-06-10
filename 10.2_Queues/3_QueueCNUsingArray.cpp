#include<iostream>
using namespace std;
#include<cstring>
template <typename T>
class Q
{
    T *data;
    int capacity;
    int nextIndex;
    int firstIndex;
    int size;
    public:
    Q(int s)
    {
        data=new T[s];
        capacity=s;
        size=0; 
        firstIndex=-1;
        nextIndex=0;
    }
    //enqueue
    void enq(T element)
    {
        if(capacity==size)
        {
            T *n=new T[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++)
            {
                n[j]=data[i];
                j++;    
            }
            for(int i=0;i<firstIndex;i++)
            {
                n[i]=data[i];
                j++;  
            }
            delete [] data;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
            data =n;
            data[nextIndex]=element;
            nextIndex=(nextIndex+1)%capacity;
            size++;
            return;
        }
        data[nextIndex]=element;
        cout<<"Next Index : "<<nextIndex<<endl;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1)
        {
            firstIndex=0;
        } 
        size++;
    }

    //deque
    T deq()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T a=data[firstIndex];
        
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0)
        {
            firstIndex=-1;
        }
        return a;
    }
    int getsize()
    {
        return size;
    }
    int front(){
        int a=data[firstIndex];
        return a;
    }
    int isempty()
    {
        if(size==0)
        {
            return 1;
        }
        return 0;
    } 
};
int main()
{
    Q <int> q1(5);
    q1.enq(1);
    q1.enq(2);
    q1.enq(3);
    q1.enq(4);
    q1.enq(5);
    q1.enq(6);
    cout<<"Front "<<q1.front()<<endl;
    cout<<"Size "<<q1.getsize()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Dq "<<q1.deq()<<endl;
    cout<<"Size after deques "<<q1.getsize()<<endl;

    cout<<"Is empty "<<q1.isempty()<<endl;
}