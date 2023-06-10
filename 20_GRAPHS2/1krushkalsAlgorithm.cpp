#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int parent[100]={0};
class Edge{
    public :
        int src;
        int des;
        int wt;
        Edge()
        {
        }
};
int EdgeSafe(Edge edge);
int findParent(int v);
void Union(Edge edge);
int cmp(Edge e1,Edge e2)
{
    return e1.wt<e2.wt;
}

void KrushKalsAlgorithm(vector<Edge> input,int n,int  m)
{
    sort(input.begin(),input.end(),cmp);
    for(int i=0;i<m;i++)
    {
        Edge k=input[i];
        // cout<<k.src<<" - "<<k.des<<" - "<<k.wt<<endl;
    }

    vector<Edge> output; 
    int j=0;
    for(int i=0;i<n;i++) parent[i]=i;
    int co=0;
    while(co<n-1)
    {
        Edge presentEdge=input[j];
       // cout<<"************"<<endl;
        // cout<<presentEdge.wt<<"->"<<endl;
        int x=EdgeSafe(presentEdge);
        //cout<<"x : "<<x<<endl;
        if(x==1)
        {
           // cout<<"hai"<<endl;
            Union(presentEdge);
            //for(int i=0;i<n-1;i++) cout<<parent[i] <<" ";
            //cout<<endl;
            output.push_back(presentEdge);
            co++;
        }
        j++;
    }
    int sum=0;
    for(auto k: output)
    {
        sum+=k.wt;
        if(k.src<k.des) cout<<k.src<<" - "<<k.des<<" - "<<k.wt<<endl;
        else cout<<k.des<<" - "<<k.src<<" - "<<k.wt<<endl;
        
    }

    cout<<"min cost path :"<<sum<<endl;
}
int main()
{
    int n,m;
    // Edge * input= new Edge[n];
    cin>>n>>m;
    vector<Edge> input(m); 
    for(int i=0;i<m;i++)
    {
        Edge k;
        cin>>k.src>>k.des>>k.wt;
        // cout<<k.src<<" - "<<k.des<<" - "<<k.wt<<endl;
        // input.push_back(k);
        input[i]=k;
    }
    KrushKalsAlgorithm(input,n,m);
}
int EdgeSafe(Edge edge)
{
    int a=findParent(edge.src);
    int b=findParent(edge.des);
    //cout<<edge.src<<" AND "<<edge.des<<endl;
    //cout<<a<<" = "<<b<<endl;
    if(a==b) return 0;
    else return 1;
    // return true;
}

int findParent(int v)
{
    if(parent[v]==v) return v;
    int x=findParent(parent[v]);
    parent[v]=x;
    return x;
}
void Union(Edge e)
{
    parent[e.des]=e.src;
}
