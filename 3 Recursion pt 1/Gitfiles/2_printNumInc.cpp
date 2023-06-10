#include <iostream>
using namespace std;
int printNum(int n)
{
    //base calculation
    if(n==1)
    {
        cout<<"1 ";
        return 1;
    }

    //recursion
    int ans=printNum(n-1);

    //small calculation
    cout<<n<<" ";

    return 0;
}


//github code
void print(int n){
    if(n > 0){
        print(n - 1);
        cout << n << " ";
    }
}
int main()
{
    int n=10;
    printNum(n);
    cout<<endl;
    print(n);
}