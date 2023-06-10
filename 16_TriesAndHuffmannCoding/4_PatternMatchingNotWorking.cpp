#include"3_ClassTriewithoutTerminal.cpp"
#include<string>
#include<iostream>
using namespace std;
int main()
{
    Trie t;
    string str;
    int n;
    /*cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        t.insertWord(str);
    }*/
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout<<"and : "<<t.search("and")<<endl;
    cout<<"ary : "<<t.search("ary")<<endl;
    return 0;
}