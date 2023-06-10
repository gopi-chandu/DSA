#include<iostream>
#include<vector>
using namespace std;
int checkMaxHeap(vector<int> v,int n)
{
    for(int i=0;i<n;i++)
    {
        //int childIndex=1;
        //int parentIndex=(childIndex-1)/2;
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while(leftChildIndex<n)
        {
            int maxIndex=parentIndex;
            /*int ans=v[i];
            cout<<ans<<endl;*/
            if(v[maxIndex]<v[leftChildIndex])
            {
                cout<<"hello"<<endl;
                maxIndex=leftChildIndex;
                return -1;
            }
            if(v[maxIndex]<v[rightChildIndex] && rightChildIndex<n)
            {
                maxIndex=rightChildIndex;
                return -1;
            }
            if(parentIndex==maxIndex)
            {
                break;
            }
        }
    }
    return 100;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    //now check for maxheap
    cout<<endl;
    cout<<"MaxHeap : "<<checkMaxHeap(v,n)<<endl;
}
