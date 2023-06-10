#include<iostream>
#include<queue>
using namespace std;
bool ans=false;

int bfs(int startVertex,int n,int **edges,int *visited) //here n is no of vertices
{
    queue<int> pendingNodes;
    pendingNodes.push(startVertex);
    visited[startVertex]=1;
    while(pendingNodes.size()!=0)
    {
        int currentVertex=pendingNodes.front();
        pendingNodes.pop();
        //cout<<currentVertex<<endl;
        cout<<currentVertex<<"-> ";
        for(int i=0;i<n;i++)
        {
           // cout<<"curr :"<<currentVertex<<" child : "<<i<<" visited : "<<visited[i]<<endl;
            if(visited[i]==0 && edges[currentVertex][i]==1)
            {
                // cout<<"curr :"<<currentVertex<<"child : "<<i<<endl;
                visited[i]=1;
                pendingNodes.push(i);
            }
        }
    }
    return 100;
}
int bfsAllComponents(int startVertex,int n,int **edges,int *visited)
{
    bfs(startVertex,n,edges,visited);
    for(int i=0;i<n;i++)
    {
        if(visited[i]!=1){cout<<"new component :"; bfs(i,n,edges,visited); cout<<endl;} 
    }
}
int dfs(int startVertex,int n,int **edges,int *visited)
{
    if(visited[startVertex]==1) return 0;
    visited[startVertex]=1;
    //cout<<startVertex<<endl;
    cout<<startVertex<<"-> ";
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && edges[startVertex][i]==1) dfs(i,n,edges,visited);
    }
    return 0;
}

int dfsAllComponents(int startVertex,int n,int **edges,int *visited)
{
    dfs(startVertex,n,edges,visited);
    for(int i=0;i<n;i++)
    {
        if(visited[i]!=1){cout<<"new component :"; dfs(i,n,edges,visited); cout<<endl;} 
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
    int visited[100]={0};
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //bfs
    //bfs(0,n,edges,visited);
    //dfs(2,n,edges,visited);
    //dfsAllComponents(2,n,edges,visited);
    bfsAllComponents(2,n,edges,visited);
}