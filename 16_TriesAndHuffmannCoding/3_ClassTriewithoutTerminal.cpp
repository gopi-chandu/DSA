#include"1_ClassTriesNode.cpp"
#include<string>
#include<iostream>
using namespace std;
class Trie
{
    TrieNode* root;
    public:
    Trie()
    {
        root=new TrieNode('\0');
    }
    void insertWord(TrieNode* root,string word)
    {
        //base case
        if(word.size()==0)
        {
            return;
        }
        //calculation

        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion
        insertWord(child,word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root,word);
    }
    
    bool search(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            return true;
        }
        int index=word[0]-'a';
        TrieNode* child=root->children[index];
        if(root->children[index]!=NULL)
        {
            return true && search(child,word.substr(1));
        }
        else
        {
            return false;
        }

    }
    bool search(string word)
    {
        return search(root,word);
    }

    // i did not write remove function for this
};