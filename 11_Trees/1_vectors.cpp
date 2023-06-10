#include<iostream>
using namespace std;
#include<vector>
int main()
{
    //vector<int> *vp=new vector<int>(); //dynamic vector
    vector<int> v;
    for(int i=0;i<100;i++)
    {
        cout<<"Capacity : "<<v.capacity()<<endl;
        cout<<"Size : "<<v.size()<<endl;
        v.push_back(i+1);
    }
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v[1]=100;

    //Dont use [] for inserting elements
    //v[3]=1002;
    //v[4]=1234;

    v.push_back(23);
    v.push_back(234);
    v.pop_back();
    /*for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }*/

   /* cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl;   //garbage
    cout<<v[6]<<endl;   //garbage
    

    cout<<"Size "<<v.size()<<endl;
    cout<<v.at(3)<<endl;
    cout<<v.at(6)<<endl;
    */


}