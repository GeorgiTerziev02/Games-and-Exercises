#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n;
    int a[n+1];
    cin>>m;

    for(int i=0;i<n+1;i++)
    {
        a[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;

        a[x]=1;
    }
    int br=0;
    int i=0;

    while(i<n+1)
    {
        if(a[i]==1)
        {
            i++;
            br++;
        }
        else if(i+4>n) break;
        else if(i+3>n) break;
        else if(i+2>n) break;
        else if(i+1>n) break;

        else if(a[i+4]==0)
        {
         br++;
         i+=4;
        }
        else if(a[i+3]==0)
        {
            br++;
            i+=3;
        }
        else if(a[i+2]==0)
        {
            br++;
            i+=2;
        }
        else
        {
            br++;
            i+=1;
        }

    }
cout<<br;
cout<<endl;
return 0;}
