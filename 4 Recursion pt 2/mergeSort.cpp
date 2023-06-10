#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums,int l1,int r1,int l2,int r2){
    int n1=r1-l1+1;
    int n2=r2-l2+1;
    vector<int> a(n1);
    vector<int> b(n2);
    vector<int> c(r2-l1+1);
    for(int f=0;f<n1;f++){
        a[f]=nums[l1+f];
    }
    for(int f=0;f<n2;f++){
        b[f]=nums[l2+f];
    }
    cout<<"HEllo"<<endl;
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
            k++;
        }else{
            c[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        c[k]=b[j];
        j++;
        k++;
    }

    for(int i=0;i<(r2-l1+1);i++){
        nums[l1+i]=c[i];
    }

}

void mergeSort(vector<int>& nums,int start,int end){
    if(start>=end) return ;
    
    mergeSort(nums,start,(start+end)/2);
    mergeSort(nums,((start+end)/2)+1,end);
    merge(nums,start,(start+end)/2,((start+end)/2)+1,end);
}

int main()
{
    int a[]={5,4,2,1,4,3,5,6,4};
    int n=sizeof(a)/sizeof(a[0]);
    
    
    vector<int> v;
    for (int i=0;i<n;i++)
    {
        v.push_back(a[i]);
        cout<<a[i]<<" ";
    }
    cout<<endl;
    mergeSort(v,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}