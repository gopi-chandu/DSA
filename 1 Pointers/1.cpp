#include<iostream>
using namespace std;
int main(){
    int i=10;
    int *p=&i;
    
    int a[3]={1,2,3};
    int *pa=a;
/*    cout<<a<<endl;
    cout<<pa<<endl;
    cout<<sizeof(p)<<endl;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(pa)<<endl;
    (*p)++;
    cout<<i<<endl;*/

    cout<<p<<endl;
    cout<<p+1<<endl;

    double d=100.0;
    double *dp=&d;
    cout<<dp<<endl;
    cout<<dp+1<<endl;

    for(int i=0;i<3;i++)
    {
        cout<<*(a+i)<<endl;
    }
}