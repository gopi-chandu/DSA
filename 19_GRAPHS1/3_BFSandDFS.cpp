#include<iostream>
#include<queue>
using namespace std;
void printDFS(int**edges,int n,int start,bool* visited)
{
    cout<<start<<endl;
    visited[start]=true;
    for(int i=0;i<n;i++)
    {
        if(start==i) continue;
        if(edges[start][i]==1) //check if edge is present
        {
            if(visited[i]) continue;
            printDFS(edges,n,i,visited); 
        }
    }
}
void printBFS(int **edges,int n,int start,bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start]=true;
    while(pendingVertices.size()!=0)
    {
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==currentVertex) continue;
            if(edges[currentVertex][i]==1 && !visited[i])
            {
                visited[i]=true;
                pendingVertices.push(i);
            }
        }
    }
}

void DFS(int ** edges,int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;

    for(int i=0;i<n;i++)
    {
        if(!visited[i]) printDFS(edges,n,i,visited);
    }
    delete [] visited;
}

void BFS(int **edges,int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;

    for(int i=0;i<n;i++)
    {
        if(!visited[i]) printBFS(edges,n,i,visited);
    }
    delete [] visited;
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
    
    cout<<"DFS "<<endl; 
    DFS(edges,n);   
    cout<<"BFS "<<endl;
    BFS(edges,n);

}