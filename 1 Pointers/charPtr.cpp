#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3};
    char b[]="abc";
    cout<<a<<endl; // this prints address of a[0]
    cout<<b<<endl; //this char address prints whole array till /0 is found

    char *c =&b[0];
    cout<<c<<endl;

    char c1='k';
    char *pc=&c1;
    cout<<c1<<endl;
    cout<<pc<<endl; // here there is only one char in c1 ,this char address prints whole array till /0 is found

}