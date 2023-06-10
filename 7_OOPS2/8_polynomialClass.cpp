#include<iostream>
using namespace std;
class polynomial{
    public:
    int *degreeCof;
    int capacity;
    polynomial()
    {
        capacity=5;
        degreeCof=new int [5];
        for(int i=0;i<capacity;i++)
        {
            degreeCof[i]=0;
        }
        /*for(int i=0;i<capacity;i++)
        {
            cout<<"Coefficient of : "<<i<<endl;
            int power;
            cin>>power;
            degreeCof[i]=power
        } */
    }
    polynomial(polynomial const &p)
    {   
        int *degreeCof=new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        {
            this->degreeCof[i]=p.degreeCof[i];
        }
        
        this->capacity=p.capacity;
    }
    polynomial operator=(polynomial const &p)
    {   
        int *degreeCof=new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        {
            this->degreeCof[i]=p.degreeCof[i];
        }
        this->capacity=p.capacity;
    }

    void add(int power,int coff)
    {
        if(power==capacity)
        {
            int *nextdata=new int [2*capacity];
            for(int i=0;i<capacity;i++)
            {
                nextdata[i]=degreeCof[i];
            }
            delete [] degreeCof;
            degreeCof=nextdata;
            for(int j=capacity;j<(capacity*2);j++)
            {
                degreeCof[j]=0;
            }
            degreeCof[power]=coff;
            capacity*=2;
        }
        else if(power<capacity)
        {
            this->degreeCof[power]=coff;
        }
        else{
            return;
        }
    }
    void display()
    {
        for(int i=capacity-1;i>=0;i--)
        {
            if(this->degreeCof[i]!=0)
            {
                cout<<this->degreeCof[i]<<" x ("<<i<<")"<<" ";
            }
        }
        cout<<endl;
    }

};

int main()
{
    polynomial p1,p2;
    p1.add(0,2);
    p1.add(1,98);
    p1.add(2,25);
    p1.add(3,73);
    p1.add(5,99);
    /*cout<<"p1 : ";;p1.display();

    p2=p1;
    cout<<"p2 : ";p2.display();
    p1.add(2,6);
    cout<<"p2 : ";p2.display();
    cout<<"p1 : ";p1.display();
    cout<<endl;*/
    polynomial p3(p1);
    cout<<"p3 : ";p3.display();
    p1.add(3,66);
    cout<<"p3 : ";p3.display();
    cout<<"p1 : ";p1.display();
    cout<<endl;
}