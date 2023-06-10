#include<iostream>
using namespace std;
#include<vector>
class maxPriorityQueue
{
    vector<int> pq;
    public:
    int getSize()
    {
        return pq.size();
    }
    int isEmpty()
    {
        return pq.size()==0;
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex=pq[pq.size()-1];
        while (childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]>pq[parentIndex])
            {
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else
            {
                break;
            }
            childIndex=parentIndex;
        }    
    }
    int removeMax()
    {
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=pq[0];
        int leftChildIndex=(2*parentIndex)+1;
        int rightChildIndex=(2*parentIndex)+2;
        while(leftChildIndex<pq.size())
        {
            int maxIndex=parentIndex;
            if(pq[leftChildIndex]>pq[maxIndex])
            {
                maxIndex=leftChildIndex;
            }
            if(pq[rightChildIndex]>pq[maxIndex])
            {
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex)
            {
                break; // it is in the right position
            }
            int temp=pq[maxIndex];
            pq[maxIndex]=pq[parentIndex];
            pq[parentIndex]=pq[maxIndex];
            parentIndex=maxIndex;

            leftChildIndex=(2*parentIndex)+1;
            rightChildIndex=(2*parentIndex)+2;
        }
        return ans;
    }
    int getMax()
    {
        return pq[0];
    }
};