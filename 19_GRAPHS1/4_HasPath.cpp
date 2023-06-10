#include<iostream>
#include<queue>
using namespace std;
bool ans=false;
bool DFS(int **edges,int n,int sv,int end,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    if(end==sv) {ans= true; return ans;}
    for(int i=0;i<n;i++)
    {
        if(i==sv) continue;
        if(edges[sv][i]==1 &&!visited[i]) 
        {
            DFS(edges,n,i,end,visited);  
        }
    }
    return ans;
}
bool BFS(int **edges,int n,int start,int end,bool *visited)
{
    queue<int> pendingvertices;
    pendingvertices.push(start);
    visited[start]=true;
    while(pendingvertices.size()!=0)
    {
        int current=pendingvertices.front();
        pendingvertices.pop();
        cout<<current<<endl;
        if(current==end)
        {
            ans=true;
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            if(i==start) continue;
            if(!visited[i] && edges[current][i] ==1)
            {
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
bool hasPath(int **edges,int n,int start,int end)
{
    bool * visited=new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;

    //bool a=DFS(edges,n,start,end,visited);
    bool a=BFS(edges,n,start,end,visited);
    delete [] visited;
    return a;
}
vector<int>* GetPath(int **edges,int n,int start,int end,bool *visited)
{
    
    if(start==end)
    {
        vector<int> *ans=new vector<int>;
        ans->push_back(end);
        return ans;
    }
    vector<int> *temp=NULL;
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(i==start)continue;
        if(!visited[i] && edges[start][i]==1)
        {
            vector<int> *temp2=GetPath(edges,n,i,end,visited);
            if(temp2!=NULL)
            {
                temp=temp2;
                break;
            }
        }
    }
    if(temp!=NULL)
    {
        temp->push_back(start);
    }
    
    return temp;
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
    
    int start,end;
    cin>>start>>end;
     cout<<"Has Path : "<<hasPath(edges ,n,start,end);
    bool * visited=new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;
    cout<<"Get Path : "<<endl;
    vector<int> *a=GetPath(edges ,n,start,end,visited);
    if(a==NULL) return 0;
    
    for(int i=0;i<a->size();i++) cout<<a->at(i)<<" ";  
    

}