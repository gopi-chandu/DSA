#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#include "2_TreesClass.h"
TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cin>>rootData;
    TreeNode<int> * root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            int childData; 
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int>* root)
{
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
TreeNode<int>* takeInput()
{
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    cout<<"Enter the number of children : "<<root->data<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int> *child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int> * root)
{
    //this us edge case if root is given a null pointer
    if(root==NULL)
    {
        return;
    }

    //these for loops are acting as base cases 
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {    
    printTree(root->children[i]);
    }    
}
int countNodes(TreeNode<int>* root){
    if(root==NULL)//edge case
    {
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countNodes(root->children[i]);
    }
    return ans;
}
int sumofNodes(TreeNode<int>* root)
{
    int ans=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=sumofNodes(root->children[i]);
    }
    return ans;
}
int findMax(TreeNode<int>* root)
{
    int mx=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        int k=findMax(root->children[i]);
        mx=max(mx,k);
        //mx=(mx>k)?mx:k;
    }
    return mx;
}
int heightofTree(TreeNode<int>* root)
{
    int height=0;
    int mxheight;
    for(int i=0;i<root->children.size();i++)
    {
        mxheight=heightofTree(root->children[i]);
        height=(height>mxheight)?height:mxheight;
        
    }
    height+=1;
    return height;
}
int printatLevelK(TreeNode<int> * root,int k)
{
    if(root==NULL) //edge case
    {
        return 0;
    }
    if(k==0)
    {
        cout<<root->data<<endl;
        return 0;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printatLevelK(root->children[i],k-1);
    }
}
int countLeafNodes(TreeNode<int>* root)//leaf nodes=> nodes which dont have any child
{
    
    int leafNodes=0;
    if(root->children.size()==0)
    {
        return 1;
    }
    for(int i=0;i<root->children.size();i++)
    {
        leafNodes+=countLeafNodes(root->children[i]);
    }
    return leafNodes;
}
// traversal types pre ,post
int preorder(TreeNode<int>* root)
{
    if(root==NULL) //edge case
    {
        return 0;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorder(root->children[i]);
    }
}
int postorder(TreeNode<int>* root)
{
    if(root==NULL) //edge case
    {
        return 0;
    }
    for(int i=0;i<root->children.size();i++)
    {
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

//you must use post order to delete the tree - delete children, root
int deleteTree(TreeNode<int>* root)
{
    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root; 
}

int nodeGreatorThanX(TreeNode<int>* root,int x)
{
    int count=0;
    if(root->data>x)
    {
        count++;
    }
    for(int i=0;i<root->children.size();i++)
    {
        count+=nodeGreatorThanX(root->children[i],x);
    }
    return count;
}
bool structurallyIdentical(TreeNode<int>* root1,TreeNode<int>* root2)
{
    //base case
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1->children.size()!=root2->children.size())
    {
        return false;
    }
    for(int i=0;i<root1->children.size();i++)
    {
        TreeNode<int>* child1=root1->children[i];
        TreeNode<int>* child2=root2->children[i];
        if (structurallyIdentical(child1,child2))
        {
            //cout<<"hello"<<endl;
        }
        else{
            return false;
        }
    }
    return true;
}
TreeNode<int>* secondLargest(TreeNode<int>* root)
{
    queue<TreeNode<int>*> q;
    stack<TreeNode<int>*> s;
    q.push(root);
    TreeNode<int>* next=new TreeNode<int>(0);
    for(int i=0;q.size()!=0;i++)
    {
        TreeNode<int>* front=q.front();
        q.pop();
        if(front->data>next->data)
        {
            s.push(front);
            //cout<<front->data<<" "<<endl;
            next=front;
        }
        for(int i=0;i<front->children.size();i++)
        {
            q.push(front->children[i]);
        }
    }
    if(s.empty()==true|| s.size()==1)
    {   
        return NULL;
    }
    s.pop(); //removes the largest element
    return s.top();
}
//return Node with Next largest element less than n
TreeNode<int>* NextLargestElementAfterN(TreeNode<int>* root,int n)
{
    if(root==NULL)
    {
        return NULL;
    }
    TreeNode<int>* result=root;
    int diff=INT8_MAX;
    queue<TreeNode<int>*> q;
    q.push(root);
    for(int i=0;q.size()!=0;i++)
    {
        TreeNode<int>* front=q.front();
        q.pop();

        if(front->data-n<diff && front->data>n)
        {
            result=front;
            diff=front->data-n;
        }

        for(int i=0;i<front->children.size();i++)
        {
           q.push(front->children[i]); 
        }

    }
    if(result==root)
    {
        return NULL;
    }
    return result;
}
/*int maxSumNode(TreeNode<int>* root)
{
    int large=0;
    int maxSum=0;
    
    for(int i=0;i<root->children.size();i++)
    {
        maxSum+=
    }
    return 1;
}*/
int main()
{
    /*TreeNode<int> * root =new TreeNode<int>(1);
    TreeNode<int> * node1 =new TreeNode<int>(2);
    TreeNode<int> * node2 =new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);*/
    //TreeNode<int> * root=takeInput();







    /*TreeNode<int> * root=takeInputLevelWise();
    printLevelWise(root);
    cout<<"Pre order: "<<endl;
    preorder(root);
    cout<<"Post order: "<<endl;
    postorder(root);
    //printLevelWise(root);
    //printTree(root);
    int k=1;
    int q=1;
    cout<<"Number of Nodes : "<<countNodes(root)<<endl;
    cout<<"Sum of Nodes : "<<sumofNodes(root)<<endl;
    cout<<"Maximum of Nodes : "<<findMax(root)<<endl;
    cout<<"Height of Tree : "<<heightofTree(root)<<endl;
    cout<<"Nodes at level "<<k<<": "<<endl;
    printatLevelK(root,k);
    cout<<"Number of Leaf Nodes : "<<countLeafNodes(root)<<endl;
    cout<<"Number of Nodes greatror than: "<<q<<" : "<<nodeGreatorThanX(root,q)<<endl;*/

    //Structurally Identical
    /*TreeNode<int> * root1=takeInputLevelWise();
    TreeNode<int> * root2=takeInputLevelWise();
    printLevelWise(root1);
    printLevelWise(root2);
    cout<<"Identical :"<<structurallyIdentical(root1,root2);
    */

   /*
   TreeNode<int>* root=takeInputLevelWise();
   cout<<"Second Largest: "<<secondLargest(root)->data;
   */

   int n;
   cin>>n;
   TreeNode<int>* root=takeInputLevelWise();
   cout<<"next largest than n : "<<NextLargestElementAfterN(root,n)->data;
}