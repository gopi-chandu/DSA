#include<iostream>
using namespace std;
int main(){
    string *sp=new string;
    *sp="abc";
    cout<<sp<<endl;
    cout<<*sp<<endl;

    cout<<"sp[0] : "<<sp[0]<<endl;
    sp[0]='z';
    cout<<"sp[0] : "<<sp[0]<<endl;
    string s="a";
    cout<<"sp : "<<sp<<endl;
    cout<<"Enter a string : "<<endl;
    getline(cin,s);
    cout<<s<<endl;
    string s2;
    s2=*sp+s;
    cout<<s2<<endl;
    cout<<"size of s2 : "<<s2.size()<<endl;
    cout<<"substring of s2 : "<<s2.substr(1)<<endl;
    int index=0,length=2;
    cout<<"substring of s2 : "<<s2.substr(index,length)<<endl;
    delete sp;
}