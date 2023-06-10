#include<iostream>
using namespace std; 
//min heaps
void heapSort(int *input,int n)
{
    //inserting elements
    for(int i=1;i<n;i++)
    {
        int childIndex=i;
        
        while(childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(input[childIndex]<input[parentIndex])
            {
                int temp=input[childIndex];
                input[childIndex]=input[parentIndex];
                input[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    //Remove Elements
    int size=n;
    int minIndex=0;
    int parentIndex=0;
    while(size>0)
    {
        int temp=input[0];
        input[0]=input[n-1];
        input[n-1]=temp;
        size--;
        parentIndex=0;
        int leftChildIndex=(2*parentIndex)+1;
        int rightChildIndex=(2*parentIndex)+2;
        while(leftChildIndex<size)
        {
            leftChildIndex=(2*parentIndex)+1;
            rightChildIndex=(2*parentIndex)+2;
           if(input[leftChildIndex]<input[parentIndex]) minIndex=leftChildIndex;
           else minIndex=parentIndex;

           if(input[rightChildIndex]<input[minIndex]) minIndex=rightChildIndex;

           swap(input[minIndex],input[parentIndex]);
           parentIndex=minIndex;
        }
    }
     
}
int main()
{
    int input[]={5,1,2,0,8};
    heapSort(input,5);
    for(int i=0;i<5;i++)
    {
        cout<<input[i]<<" ";
    }
}