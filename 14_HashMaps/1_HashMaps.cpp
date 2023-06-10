#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>
int main()
{
    unordered_map<string,int> ourmap;

    //Insert
    pair<string,int> p("abc",1);
    ourmap.insert(p);
    ourmap["def"]=2;

    //find or accessing
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;

    //cout<<ourmap.at("ghi")<<endl; - dont use this as ghi doenot exist
    cout<<"Size : "<<ourmap.size()<<endl;
    cout<<ourmap["ghi"]<<endl;
    cout<<"Size : "<<ourmap.size()<<endl;


    //check Presence
    if(ourmap.count("ghi")>0)
    {
        cout<<"ghi is present"<<endl;
    }

    //erase
    ourmap.erase("ghi");
    if(ourmap.count("ghi")>0)
    {
        cout<<"ghi is present"<<endl;
    }
    cout<<"Size : "<<ourmap.size()<<endl;
}