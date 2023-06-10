//length of string
//remove x from the string axbcxde ->abcde
#include<iostream>
using namespace std;
int lengthOfString(char str[])
{
    //base case
    if (str[0]=='\0')
    {
        return 0;
    }

    //recursion
    int ans=lengthOfString(str+1);

    //small calculation
    ans=ans+1;
    return ans;
}
int lengthOfStringshortcode(char str[])
{
    //base case
    if (str[0]=='\0')
    {
        return 0;
    }

    //recursion +smallcalculation
    return lengthOfString(str+1)+1;


}

int removeX(char str[])
{
    //base case
    if(str[0]=='\0')
    {
        return 0 ;
    }
    
    //recursion
    //small calculation beginning x , second value =x
   /*if(str[0]!='x')
    {
         removeX(str+1);
    }
    else{
        int i=0;
        for(;str[i]!='\0';i++)
        {
            str[i]=str[i+1]; // this continues till the letter before /0 so to shift /0 we need to change
        }
        str[i]=str[i+1];// move forward /0
        removeX(str);  
    }*/

    if(str[0]=='x')
    {
        int i=0;
        for(;str[i]!='\0';i++)
        {
            str[i]=str[i+1]; // this continues till the letter before /0 so to shift /0 we need to change
        }
        str[i]=str[i+1];
        removeX(str);
    }
    else{
        removeX(str+1);
    }

}
int main()
{
    char str[100];
    cin>>str;

    cout<<str<<endl;
    cout<<lengthOfStringshortcode(str)<<endl;
    removeX(str);
    cout<<str<<endl;
}