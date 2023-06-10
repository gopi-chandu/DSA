#include<bits/stdc++.h>
#include<queue>
#include "binarySearchTreeCN.h"
using namespace std;
int printTreeLevelWise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<BinaryTreeNode<int>*> pendingNodes; 
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<"R"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
        
    }
    return 0;
}

int main()
{
    BST* tree=new BST;
    int s[]={4 ,2 ,6, 1, 3, 5 ,7,9 };
    int sample[]={10 ,5 ,20, 7, 3, 15,9,20,21 };
    int n=sizeof(sample)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        tree->root=tree->insert(s[i]);
    }
    printTreeLevelWise(tree->root);
    cout<<"HELLO"<<endl;
    //tree->root=tree->deleteData(7);
    //printTreeLevelWise(tree->root);
    cout<<"IS balanced : "<<tree->isBalanced(tree->root);
}
