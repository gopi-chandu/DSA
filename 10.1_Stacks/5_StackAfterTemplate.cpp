#include<iostream>
using namespace std;
template <typename T>
class StackUsingArray
{   T *data;
    int nextindex;
    int capacity;

    public:

    StackUsingArray(){
        data=new T[5];
        nextindex=0;
        capacity=5;
    }
    T top()
    {
        if(isempty())
        {
            cout<<"Empty Stack "<<endl;
            return 0;
        }
        return data[nextindex-1];
    }
    int size()
    {
        return nextindex;
    }
    bool isempty()
    {
        return (nextindex==0);
    }
    void push(T a)
    {
        if(nextindex==capacity)
        {
            T *newdata= new T[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity=capacity*2;
            delete [] data ; 
            data=newdata;
        }
        data[nextindex]=a;
        nextindex++;
    }
    T pop()
    {
        if(isempty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }
};