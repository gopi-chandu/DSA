#include<iostream>
using namespace std;
#include "3_PairClass.cpp"
int main()
{
    Pair <Pair<int,int>,int> p1;
    p1.setY(10);
    Pair <int,int>p2;
    p2.setX(15);
    p2.setY(16);
    p1.setX(p2);
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;
    cout<<p2.getX()<<" "<<p2.getY()<<endl;

   /* Pair <int,double>p1;
    p1.setX(10);
    p1.setY(11.1);
    cout<<p1.getX()<<endl;
    cout<<p1.getY()<<endl;
*/



    /*Pair<int> p1;
    p1.setX(10);
    p1.setY(15);
    cout<<p1.getX()<<endl;
    cout<<p1.getY()<<endl;
    Pair <double> p2;
    p2.setX(10.1);
    p2.setY(9.99);
    cout<<p2.getX()<<endl;
    cout<<p2.getY()<<endl;
    Pair<char> p3;*/
    
}
