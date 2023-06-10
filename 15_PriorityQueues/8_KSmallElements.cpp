#include<iostream>
using namespace std;
#include<queue>
int kSmallestElements(int *input,int n,int k)
{
    priority_queue<int> p;
    for(int i=0;i<k;i++)
    {
        p.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++)
    {
        if(p.top()>input[i])
        {
            int temp=p.top();
            p.pop();
            p.push(input[i]);
            input[i]=temp;
        }
    }

    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
        

}
int main()
{
    int n,k;
    cin>>n;
    int* input=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    cin>>k;
    kSmallestElements(input,n,k);
    cout<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<input[i]<<" ";
    }
    delete input;
}