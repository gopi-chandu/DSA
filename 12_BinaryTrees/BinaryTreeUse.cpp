#include<bits/stdc++.h>
#include<queue>
#include "BinaryTreeClass.h"
using namespace std;
/*int print(BinaryTreeNode<int>* root)
{
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    /*for(int i=0;pendingnodes.size();i++)
    {
        BinaryTreeNode <int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<": ";
        cout<<front->left->data<<","<<front->right->data<<endl;
        pendingnodes.push(front->left);
        pendingnodes.push(front->right);
        cout<<endl;
    }

    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode <int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<": ";
        cout<<front->left->data<<","<<front->right->data<<endl;
        if(front->left!=NULL)
        {
            pendingnodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            pendingnodes.push(front->right);
        }
        cout<<endl;
    }
}*/
int printTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL)
    {
        cout<<"L "<<root->left->data<<",";
    }
    if(root->right!=NULL)
    {
        cout<<"R "<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    if(rootData==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int> * root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> * leftChild=takeInput();
    BinaryTreeNode<int> * rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
}
BinaryTreeNode<int>* takeInputLevelWise()
{
    cout<<"Enter Root data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        int rightChildData;
        cout<<"Enter Right child of "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData!=-1)
        {
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

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
int countNodes(BinaryTreeNode<int>* root)
{
    int answer=1, countLeft,countRight;
    if(root==NULL)
    {
        return 0;
    }
    answer+=countNodes(root->left);
    answer+=countNodes(root->right);
    return answer;
}
int countNodesCN(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+countNodesCN(root->left)+countNodesCN(root->right);
}
int preorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
int postorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);
}
int inorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
BinaryTreeNode<int>* buildTreeHelper(int *in,int *pre,int inS,int inE,int preS,int preE)
{
    if(inS>inE)
    {
        return NULL;
    }
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==rootData)
        {
            rootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=rootData-1;
    int lPreS=preS+1;
    int lPreE=lPreS+lInS-lInE;
    
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in,pre,lInS,lInE,lPreE,lPreS);
    root->right=buildTreeHelper(in,pre,rInS,rInE,rPreE,rPreS);

    return root; 
}
BinaryTreeNode<int>* buildTree(int* in,int* pre,int size)
{
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}

//Diameter of a binary tree= max distance between nodes
int height(BinaryTreeNode<int>* root)
{
    if(root=NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}
pair<int,int> heightDiameter(BinaryTreeNode<int>* root)
{
    //base case
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int> rightAns=heightDiameter(root->right);
    int ld=leftAns.second;
    int lh=leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;

    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}
int main()
{
    /*BinaryTreeNode<int >* root=new BinaryTreeNode<int>(1);
    BinaryTreeNode <int>* node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode <int>* node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;*/

    BinaryTreeNode<int>* root=takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<"The Number of Nodes : "<<countNodesCN(root)<<endl;
    cout<<"Inorder : "<<endl;inorder(root);cout<<endl;
    cout<<"Pre order : "<<endl;postorder(root);cout<<endl;
    //cout<<"Post order : "<<endl;preorder(root);
    //cout<<"Diameter : "<<endl; cout<<diameter(root);
    //build tree from inorder and preorder not working
    /*int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};

    BinaryTreeNode<int>* root2=buildTree(in,pre,9);
    cout<<root2->data;*/
    //delete root;
    pair<int,int> p=heightDiameter(root);
    cout<<"Height : "<<p.first<<endl;
    cout<<"Diameter : "<<p.second;


}