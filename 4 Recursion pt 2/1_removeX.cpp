#include<iostream>
using namespace std;
void removeX(char s[]){
    //base case
    if(s[0]=='\0')
    {
        return ;
    }

    if(s[0]!='x')
    {
        removeX(s+1);
    }
    else{
        int i=1;
        for (i;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
    }

}

int main(){
   char str[]="abxcxdxexf";
   cout<<str<<endl;
    removeX(str);
    cout<<str;
    return 0;
}