#include<iostream>
using namespace std;
int m=1e7;
//recursion
int balancedBST(int h)
{
    if(h==1 || h==0) return 1;
    int x=balancedBST(h-1);
    int y=balancedBST(h-2);
    int ans=(x*x)+2*x*y;
    return ans;
}
//memeoisation
int balancedBSTmemo(int h,int *array)
{
    if(array[h]!=-1)
    {
        return array[h];
    }
    if(h==1 || h==0) 
    {
        array[h]=1;
        return 1;
    }
    int x=balancedBST(h-1);
    int y=balancedBST(h-2);
    int ans=(x*x)+2*x*y;
    array[h]=ans;
    return array[h];
}

int balancedBST_Dynamic(int h)
{
    int array[1000];
    for(int i=0;i<1000;i++)
    {
        array[i]=-1;
    }
    array[1]=1;array[0]=1;
    if(array[h]!=-1) return array[h];
    for(int i=2;i<=h;i++)
    {
        array[i]=array[i-1]*array[i-1]+2*array[i-2]*array[i-1];
    }
    return array[h];
}
int main()
{
    int array[1000];
    for(int i=0;i<1000;i++)
    {
        array[i]=-1;
    }
    cout<<"Balanced BST : "<<balancedBST(3)<<endl;
    cout<<"Balanced BST (Memoization) : "<<balancedBSTmemo(5,array)<<endl;
    cout<<"Balanced BST (DP) : "<<balancedBST_Dynamic(5)<<endl;
}