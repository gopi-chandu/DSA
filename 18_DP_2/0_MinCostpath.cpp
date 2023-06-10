#include<iostream>
using namespace std;
int minimumCost(int **input,int m,int n,int i,int j)
{
    if((i==m-1) && (j==n-1))
    {
     return input[i][j];
    } 
    if(i>=m || j>=n) return INT8_MAX;
    int x=minimumCost(input,m,n,i,j+1);
    int y=minimumCost(input,m,n,i+1,j);
    int z=minimumCost(input,m,n,i+1,j+1);
    int ans=input[i][j]+min(x,min(y,z));
    return ans;
}
//MEMOISATION

int minimumCostM(int **input,int m,int n,int i,int j,int **output)
{
    if((i==m-1) && (j==n-1))
    {
        output[i][j]=input[i][j];
        return output[i][j];
    } 
    if(i>=m || j>=n) return INT8_MAX;
    if(output[i][j]!=-1) return output[i][j];
    int x=minimumCost(input,m,n,i,j+1);
    int y=minimumCost(input,m,n,i+1,j);
    int z=minimumCost(input,m,n,i+1,j+1);
    output[i][j]=input[i][j]+min(x,min(y,z));
    return output[i][j];
}
//DP
int minimumCostDP(int **input,int m,int n,int** outputDP)
{
    outputDP[m-1][n-1]=input[m-1][n-1];
    //fill last row (right to left)
    for(int j=n-2;j>=0;j--)
    {
        outputDP[m-1][j]=outputDP[m-1][j+1]+input[m-1][j];
    }
    //fill the last column (bottom to top)
    for(int i=m-2;i>=0;i--)
    {
        outputDP[i][n-1]=outputDP[i+1][n-1]+input[i][n-1];
    }
    //fill remianing cells
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            //cout<<"Hello "<<endl;
            outputDP[i][j]=min(outputDP[i+1][j],min(outputDP[i+1][j+1],outputDP[i][j+1]))+input[i][j];
        }
    }
    
   // cout<<outputDP[0][0];
    return outputDP[0][0];
}
int main()
{
    int m,n,k;
    cin>>m>>n;
    //dynamcic allocation
    int **input=new int*[m];
    for(int i=0;i<n;i++) input[i]=new int[n];
    //-----------
    //input
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>input[i][j];
    //output
    for(int i=0;i<m;i++) 
    {
        for(int j=0;j<n;j++)
        {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    } 
    //cout<<"Answer : "<<endl;
   // cout<<minimumCost(input,m,n,0,0)<<endl;

    //output array
    int **output=new int*[m];
    for(int i=0;i<m;i++) output[i]=new int [n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) output[i][j]=-1;
    //output array 2
    int **outputDP=new int*[m];
    for(int i=0;i<m;i++) outputDP[i]=new int [n];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) outputDP[i][j]=-1;

   // cout<<"Answer Memoisation : "<<endl;
    //cout<<minimumCostM(input,m,n,0,0,output)<<endl;

    cout<<"Answer DP : "<<endl;
    cout<<minimumCostDP(input,m,n,outputDP)<<endl;

    //Deleteing Dynamically Allocated Arrays
    for(int i=0;i<m;i++)
    {
        delete [] output[i];
        delete [] outputDP[i];
        delete[] input[i];
    }
    delete input;
    delete output;
}