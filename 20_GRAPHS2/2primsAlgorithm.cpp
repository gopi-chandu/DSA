#include<iostream>
#include<vector>
using namespace std;
int findMinVertex(int *weight,int *visited,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 | weight[minVertex]>weight[i]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void PrimsAlgorithm(vector<vector<pair<int ,int>>> input,int n,int  m)
{
    int parent[100]={0};
    int visited[100]={0};
    int weight[100];
    //weight of each edge is set to infinity
    for(int i=0;i<n;i++) weight[i]=INT16_MAX;
    weight[0]=0; //zero to zero the weight is zero
    parent[0]=-1;
    for(int i=0;i<n;i++)
    {
        // find min vertex 
        int minVertex=findMinVertex(weight,visited,n);
        visited[minVertex]=1;
        for(int j=0;j<input[minVertex].size();j++)
        {
            //other end
            int wt=input[minVertex][j].second;
            int child=input[minVertex][j].first;
            if(visited[child]==0 && wt<weight[child])
            {
                parent[child]=minVertex;
                weight[child]=wt;
            }
        }
        
    }
    cout<<"V - P - Wt"<<endl;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else 
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        sum+=weight[i];
    }

    cout<<"Minimum Spanning Tree "<<endl;
    cout<<"Sum : "<<sum<<endl;  
    cout<<"hey "<<endl;
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
    PrimsAlgorithm(input,n,m);
}



