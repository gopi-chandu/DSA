#include<iostream>
using namespace std;
class StackUsingArray
{   int *data;
    int nextindex;
    int capacity;
    public:
    StackUsingArray(){
        data=new int[5];
        nextindex=0;
        capacity=5;
    }
    int top()
    {
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
    void push(int a)
    {
        if(nextindex==capacity)
        {
            int *newdata= new int[2*capacity];
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
    int pop()
    {
        if(isempty())
        {
            cout<<"Stack is empty"<<endl;
            return INT8_MIN;
        }
        nextindex--;
        return data[nextindex];
    }
};