#include<bits/stdc++.h>
#include<queue>
#include "binaryTreeClass.h"
using namespace std;

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
//binary search
BinaryTreeNode<int>* BinarySearch(BinaryTreeNode<int>* root,int n)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n)
    {
        return root;
    }
    if(root->data>n)
    {
        return BinarySearch(root->left,n);
    }
    else
    {
        return BinarySearch(root->right,n);
    }   
}
//print level wise
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
//building Tree from sorted array
BinaryTreeNode<int>* tree(int *a,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(a[mid]);
    root->left=tree(a,start,mid-1);
    root->right=tree(a,mid+1,end);
    
    return root;
}
BinaryTreeNode<int>* buildBSTfromSortedArray(int* a,int size)
{
    int start=0;
    int end=size-1;
    return tree(a,start,end);
}
//print in range
int printInRange(BinaryTreeNode<int>* root,int lowerLimit,int upperLimit)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data>lowerLimit)
    {
        printInRange(root->left,lowerLimit,upperLimit);
    }
    if(root->data>=lowerLimit&& root->data<=upperLimit)
    {
        cout<<root->data<<endl;
    }
    if(root->data<=upperLimit)
    {
        printInRange(root->right,lowerLimit,upperLimit);
    }
   return 0;
}

//Is bst has complexitiy of o n*2 
int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return true;
    }
    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool output=(root->data>leftMax)&&(root->data<=rightMin)&&isBST(root->left)&&isBST(root->right);
    return output;
}

class isBSTReturn{
    public:
        bool isBST;
        int maximum;
        int minimum;
};
isBSTReturn isBST2(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        isBSTReturn output;
        output.isBST=true;
        output.maximum=INT_MIN;
        output.minimum=INT_MAX;
        return output;
    }
    isBSTReturn leftOutput=isBST2(root->left);
    isBSTReturn rightOutput=isBST2(root->right);
    int minimum=min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum=max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTfinal=(root->data>leftOutput.maximum) && (root->data<=rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);
    //cout<<"bool "<<isBSTfinal<<endl;
    isBSTReturn output;
    output.isBST=isBSTfinal;
    output.maximum=maximum;
    output.minimum=minimum;
    return output;
}

bool isBST3(BinaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data<min || root->data>max)
    {
        return false;
    }
    bool isLeftOk=isBST3(root->left,min,root->data-1);
    bool isrightOk=isBST3(root->right,root->data,max);
    return isrightOk && isLeftOk;
}
int inorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
    return 0;
}

//binary search trees to linked list
class node{
    public:
        int data;
        node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class HT{
    public:
        node* head;
        node* tail;      
};
HT BSTtoLL(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        HT output;
        output.head=NULL;
        output.tail=NULL;
        return output;
    }
    HT left=BSTtoLL(root->left);
    HT right=BSTtoLL(root->right);
    node * llmid=new node(root->data);  
    if(left.tail!=NULL)
    {
        left.tail->next=llmid;
        llmid->next=right.head;
    }
    HT output;
    if(left.head!=NULL)
    {
        output.head=left.head;
    }
    else{
        output.head=llmid;
    }
    if(right.tail!=NULL)
    {
        output.tail=right.tail;
    }
    else{
        output.tail=llmid;
    }

    return output;
}
///4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1  bst
//to find path of a number - from root to the number
vector<int> * BSTpath(BinaryTreeNode <int>* root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftAns=BSTpath(root->left,data);
    if(leftAns!=NULL)
    {
        leftAns->push_back(root->data);
        return leftAns;
    }
    vector<int>* rightAns=BSTpath(root->right,data);
    if(rightAns!=NULL)
    {
        rightAns->push_back(root->data);
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{

    BinaryTreeNode<int>* root= takeInputLevelWise();
    printTreeLevelWise(root);
    /*BinaryTreeNode<int>* ans=BinarySearch(root,11);
    cout<<endl;
    if(ans!=NULL)
    {
        cout<<"Found "<<ans->data<<endl;
    }*/
    cout<<"print in Range"<<endl;
    printInRange(root,6,10);
    cout<<"is BST : "<<isBST(root)<<endl;
    cout<<"is BST : "<<isBST2(root).isBST<<endl;
    cout<<"Maximum : "<<isBST2(root).maximum<<endl;
    cout<<"Minimum : "<<isBST2(root).minimum<<endl;
    cout<<"is BST : "<<isBST3(root)<<endl;
    //cout<<"In Order : "<<endl;
    //inorder(root);
    cout<<"BST to LL : "<<endl;
    HT linkedList =BSTtoLL(root);
    cout<<"Head : "<<linkedList.head->data<<endl;
    cout<<"Tail : "<<linkedList.tail->data<<endl;
    cout<<"Linked List : "<<endl;
    node* temp=linkedList.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<"BST path : "<<endl;
    vector<int> *path=BSTpath(root,7);
    for(int i=0;i<path->size();i++)
    {
        cout<<path->at(i)<<endl;
    }
    delete path;
    /*int sortedArray[]={1,2,3,4,5,6,7};
    //cout<<sizeof(sortedArray);
    BinaryTreeNode<int>* root2=buildBSTfromSortedArray(sortedArray,sizeof(sortedArray)/sizeof(int));
    printTreeLevelWise(root2);*/
}

