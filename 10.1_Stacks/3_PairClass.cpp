#include<iostream>
using namespace std;
template <typename T,typename V>
class Pair{
    T x;
    V y;
    public :
    void setX(T x)
    {
        this->x=x;
    }
    void setY(V y)
    {
        this->y=y;
    }
    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};
/*
int main()
{
    Pair<int> p1;
    p1.setX(10);
    p1.setY(15);
    cout<<p1.getX()<<endl;
    cout<<p1.getY()<<endl;
    Pair <double> p2;
    p2.setX(10.1);
    p2.setY(9.99);
    cout<<p2.getX()<<endl;
    cout<<p2.getY()<<endl;
    
}
*/