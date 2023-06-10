#include<iostream>
using namespace std;
int main(){
	int i=65;
	char c=i;
	cout<<"C value : "<<c<<endl;
	int * p=&i;
	//char *pc=p; wrong use
	char *pc=(char*)p;
	cout<<p<<endl;
	cout<<*p<<endl;
	cout<<"Pc pointer"<<endl;
	cout<<pc<<endl;
	cout<<*pc<<endl;
	cout<<*(pc+1)<<endl;
	cout<<*(pc+2)<<endl;
	cout<<*(pc+3)<<endl;

} 