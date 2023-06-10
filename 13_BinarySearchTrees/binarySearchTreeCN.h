#include "binaryTreeClass.h" //for Binary tree Node
#include<bits/stdc++.h>
using namespace std;
class BST{
    
    public:
    BinaryTreeNode<int> * root;
        BST()
        {
            root=NULL;
        }
        ~BST()
        {
            delete root;
        }
        private :
        bool hasData(BinaryTreeNode<int> * node,int data)
        {
            if(node==NULL)
            {
                return false;
            }
            if(node->data==data)
            {
                return true;
            }
            else if(data<root->data)
            {
                return hasData(root->left,data);
            }
            else
            {
                return hasData(root->right,data);
            }
        }
        BinaryTreeNode<int>* insert(BinaryTreeNode<int> * node,int data)
        {
            if(node==NULL)
            {
                BinaryTreeNode<int> * node=new BinaryTreeNode<int>(data);
                return node;
            }
            if(node->data>data)
            {
                BinaryTreeNode<int> * child=insert(node->left,data);
                node->left=child;
            }
            else if(node->data<data)
            {
                BinaryTreeNode<int> * child=insert(node->right,data);
                node->right=child;
            }
            return node;
        }
        BinaryTreeNode<int>* deleteData(BinaryTreeNode<int> * node,int data)
        {
            if(node==NULL)
            {
                return NULL;
            }
           if(node->data>data)
            {
                deleteData(node->left,data);
            }
            else if(node->data<data)
            {
                deleteData(node->right,data);
            }
            else{
                if(node->left==NULL && node->right==NULL)
                {
                    delete node;
                    return NULL;
                }
                else if(node->left==NULL)
                {
                    BinaryTreeNode<int> * temp=node->right;
                    node->right=NULL;
                    delete node;
                    return temp;
                }
                else if(node->right==NULL)
                {
                    BinaryTreeNode<int> * temp=node->left;
                    node->left=NULL;
                    delete node;
                    return temp;
                }
                //both have left and right not equal to null
                else{
                    //replace by right minimum or left maximum - we chose right minimum for root
                    BinaryTreeNode<int>* minNode=node->right;
                    while(minNode->left!=NULL)
                    {
                        minNode=minNode->left;
                    }
                    int rightMin=minNode->data;
                    node->data=rightMin;
                    node->right=deleteData(node->right,rightMin);
                    return node;
                }
            }
        }
        
        public:
        bool hasData(int data){
            return hasData(this->root,data);
        }
        BinaryTreeNode<int>* insert(int data)
        {
            return insert(this->root,data);
        }
        BinaryTreeNode<int>* deleteData(int data)
        {
            return  deleteData(this->root,data);
        }
        
        int height(BinaryTreeNode<int>* root)
        {
            if(root==NULL)
            {
                return 0;
            }
            return 1+height(root->left)+height(root->right);
        }

        bool isBalanced(BinaryTreeNode<int>* root)
        {
            if(root==NULL)
            {
                return 1;
            }
            int leftHeight=height(root->left);
            int rightHeight=height(root->right);
            if(abs(leftHeight-rightHeight)<=1 && isBalanced(root->left)&&isBalanced(root->right))
            {
                return 1;
            }

            return 0 ;
        }
        int balanceFactor(BinaryTreeNode<int>* root)
        {
            if(root==NULL)
            {
                return -1;
            }
            else
            {
                return (height(root->left)-height(root->right));
            }
        }
        // avl insertion
       /* BinaryTreeNode<int>* AVLinsert(BinaryTreeNode<int> * node,int data)
        {
            if(node==NULL)
            {
                BinaryTreeNode<int> * node=new BinaryTreeNode<int>(data);
                return node;
            }
            if(node->data>data)
            {
                BinaryTreeNode<int> * child=insert(node->left,data);
                node->left=child;
            }
            else if(node->data<data)
            {
                BinaryTreeNode<int> * child=insert(node->right,data);
                node->right=child;
            }
            else{
                return node;
            }
            int bf=balanceFactor(root);
            if(bf>1 && child) 
        }*/
};