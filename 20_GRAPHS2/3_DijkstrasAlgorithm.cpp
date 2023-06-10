#include<iostream>
#include<vector>
using namespace std;
int findMinVertex(int *weight,int *visited,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 || weight[minVertex]>weight[i]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void DijkstraAlgorithm(vector<vector<pair<int ,int>>> input,int n,int  m)
{
    int parent[100]={0};
    int visited[100]={0};
    int distance[100];
    //weight of each edge is set to infinity
    for(int i=0;i<n;i++) distance[i]=INT16_MAX;
    distance[0]=0; //zero to zero the weight is zero
    parent[0]=-1;
    for(int i=0;i<n;i++)
    {
        // find min vertex 
        int minVertex=findMinVertex(distance,visited,n);
        visited[minVertex]=1;
        for(int j=0;j<input[minVertex].size();j++)
        {
            //other end
            int dis=input[minVertex][j].second+distance[minVertex]; //distance
            int child=input[minVertex][j].first; //other end of vertex
            if(visited[child]==0 && dis<distance[child])
            {
                parent[child]=minVertex;
                distance[child]=dis;
            }
        }
        
    }
    cout<<"Distances :"<<endl;
    for(int i=0;i<n;i++) cout<<distance[i]<<" ";
    return ;
}
int main()
{
    int n,m;
    // Edge * input= new Edge[n];
    cin>>n>>m;
    
    vector<vector<pair<int ,int>>> input(n);
    //cout<<"heyyy"<<endl;
    for(int i=0;i<m;i++)
    {
        int k;
        pair<int,int> p;
        cin>>k>>p.first>>p.second;
        input[k].push_back(p);   
    }
    DijkstraAlgorithm(input,n,m);
}
