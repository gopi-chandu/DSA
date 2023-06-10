#include<iostream>
using namespace std;
void print(int**edges,int n,int start,bool* visited)
{
    cout<<start<<endl;
    visited[start]=true;
    for(int i=0;i<n;i++)
    {
        if(start==i) continue;
        if(edges[start][i]==1) //check if edge is present
        {
            if(visited[i]) continue;
            print(edges,n,i,visited); 
        }
    }
}
int main()
{
    
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    //input
    for(int i=0;i<n;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    } 
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    print(edges,n,0,visited);
}
