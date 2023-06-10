#include<iostream>
using namespace std;
int main(){
    int *p=new int;
    p[0]=10;
    double *d=new double;
    d[0]=200.0;

    cout<<*p<<"  "<<*d<<endl;

    //array
    int *pa=new int[20];
    delete  [] pa;

    //2d array
    int m,n;
    cout<<"Enter rows and columns"<<endl;
    cin>>m>>n;
    int**pointer=new int*[m];
    for(int i=0;i<m;i++)
    {
        pointer[i]=new int[n];
    }
    //delete 2d array
    for(int i=0;i<m;i++)
    {
        delete [] pointer[i];
    } 
    delete pointer;
}