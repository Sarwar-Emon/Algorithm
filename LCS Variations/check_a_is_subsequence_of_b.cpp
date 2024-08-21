#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int x=0;
    bool ans=false;
    for(char c: b)
    {
        if(c==a[x])
        {
            x++;
        }
        if(x==a.size())
        {
            ans= true;
            break;
        }
    }
    if(ans) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}