#include<iostream>
#include<queue>
using namespace std;
void printBFS(int **edges,int n,int start, int * visited)
{
    cout<<start<<endl;
    visited[start]=1;
    queue<int> pendingNodes;
    pendingNodes.push(start);
    while(pendingNodes.size()!=0)
    {
        int child=pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<n;i++)
        {
            if(edges[child][i]==1)
            {
                if(visited[i]) continue;
                else{
                    cout<<i<<endl;
                    visited[i]=1;
                    pendingNodes.push(i);
                }
                
            }
        }
    }
}

void printBFSCN(int **edges,int n,int start)
{
    queue<int> pendingVertices;
    pendingVertices.push(start);
    int *visited=new int[n];
    for(int i=0;i<n;i++) visited[i]=0;
    visited[start]=1;
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
                visited[i]=1;
                pendingVertices.push(i);
            }
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
    int *visited=new int[n];
    for(int i=0;i<n;i++) visited[i]=0;
    printBFSCN(edges,n,0);

    delete [] visited;
}