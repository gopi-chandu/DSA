#include<iostream>
using namespace std;
void increment(int &n){
    n++;
}

int* f(int n){
    int i=n;
    return &i;
}

int main(){
    int i=10;
    cout<<i<<endl;
    int *p=f(i);
    cout<<"hello"<<p<<endl;
    increment(i);
    cout<<i<<endl;
}