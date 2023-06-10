#include"1_ClassTriesNode.cpp"
#include<string>
#include<iostream>
using namespace std;
class Trie
{
    TrieNode *root; 
    public:
    Trie()
    {
        root=new TrieNode('\0');
    }
    //Insert
    void insertWord(TrieNode* root,string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal=true;
            return ;
        }

        //small calcualation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursive call
        insertWord(child,word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root,word);
    }
    //Search
    bool search(TrieNode* root,string word)
    {
        //base case
        if(word.size()==0)
        {
           return root->isTerminal;
        }
        //small calculation and recursion
        int index=word[0]-'a';
        TrieNode *child=root->children[index];
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


    //Remove
    void remove(TrieNode* root,string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }
        // small calculation
        TrieNode * child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
            
        }
        else
        {
            //letter not found
            return ;
        }
        remove(child,word.substr(1));
        if(child->isTerminal==false )
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void remove(string word)
    {
        remove(root,word);
    }
};

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout<<"and : "<<t.search("and")<<endl;
    t.remove("and");
    cout<<"and : "<<t.search("and")<<endl;
}