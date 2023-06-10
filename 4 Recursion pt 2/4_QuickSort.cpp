#include<iostream>
using namespace std;
int partition(int a[],int start, int end){
    int pivot=a[start];
    int count =0;
    for(int i=start;i<=end;i++)
    {
        if (a[i]<pivot){
            count++;
        }
    }
    int temp=a[start+count];
    a[start+count]=a[start];
    a[start]=temp;
    //we have set the postion of the centre element
    int pivotIndex=start+count;
    while(start<pivotIndex && pivotIndex<end){
        if (a[start]<=a[pivotIndex])
        {
            start++;
        }
        else if(a[end]>a[pivotIndex])
        {
            end--;
        }
        else{
            int temp=a[end];
            a[end]=a[start];
            a[start]=temp;
        }
    }
    return pivotIndex;
}
void qs(int a[],int start,int end)
{
    //base case
    if (start>=end){
        return ;
    }
   int c=partition(a,start,end);
   //partition is in correct position
   qs(a,start,c-1);
   qs(a,c+1,end);
}

int main()
{
    int a[]={5,4,2,1,4,3,5,6,4};
    int n=(sizeof(a)/sizeof(a[0]));
    qs(a,0,n-1);
    
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}