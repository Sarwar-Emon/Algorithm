#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int e,n;
    cin>>e>>n;
    int adj[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            adj[i][j]=0;
            if(i==j)
            adj[i][j]=1;
            
        }
    }
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    
    return 0;
}