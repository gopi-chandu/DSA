#include<iostream>
using namespace std;
class dynamicArray{
    int nextIndex;
    int *data;
    int capacity;
    public:
    dynamicArray()
    {
        nextIndex=0;
        data=new int [5];
        capacity =5;
    }
    //copy  constructor
    dynamicArray(dynamicArray const &d)
    {
        /*
        //This is shallow copy-- which happens internally
        this->data=d.data;
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
        */
       this->data=new int[d.capacity];
       for(int i=0;i<d.nextIndex;i++)
       {
           this->data[i]=d.data[i];
       }
       this->nextIndex=d.nextIndex;
       this->capacity=d.capacity;
    }
    //copy assignment operator
    void operator=(dynamicArray const &d)
    {
        this->data=new int[d.capacity];
       for(int i=0;i<d.nextIndex;i++)
       {
           this->data[i]=d.data[i];
       }
       this->nextIndex=d.nextIndex;
       this->capacity=d.capacity;

    }
    void add(int element)
    {
        if(nextIndex==capacity)
        {
            int *newdata=new int [2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            delete [] data;
            data=newdata;
            capacity*=2;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int get (int index) const
    {
        if(index<nextIndex)
        {
            return data[index];
        }
        else
        {
            return -1;
        }
        
    }
    void add(int i,int element){
        if (i<nextIndex)
        {
            //override
            data[i]=element;
        }
        else if(i==nextIndex)
        {
            //if index = nextIndex this means adding at the end
            //calls the above function to add element
            add(element);
        }
        else{

            //when i is gretor than nextIndex
            return ;
        }
    }
    void display()  const
    {
        for(int i=0;i<nextIndex;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.display();
    dynamicArray d2(d1);
    d1.add(0,100);
    d2.display();
    d1.display();

    dynamicArray d3;

    d3=d1;
    d1.add(0,77);
    d1.display();
    d3.display();

}