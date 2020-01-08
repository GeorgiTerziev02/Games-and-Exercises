#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
bool dots[500000];
void Color(int left, int right)
{
    for(int i=left; i<=right; i++)
    {
        if(dots[i]==0)
        {
            dots[i]=1;
        }
        else
        {
            dots[i]=0;
        }
    }
}
int Count()
{
    int maxDots = 0;
    for(int i = 0; i <= 500000; i++)
    {
        if(dots[i] == 1)
        {
            int counter = 1;

            for(int j = i+1; j < 500000; j++)
            {
                if(dots[j] == 0)
                {
                    break;
                }

                counter++;
            }

            if(maxDots < counter)
            {
                maxDots = counter;
            }
        }
    }

    return maxDots;
}
int main()
{
    int operations;
    cin>>operations;

    for(int i = 0; i < operations; i++)
    {
        int left;
        int right;
        cin>>left>>right;

        Color(left,right);
    }

    cout<<Count()<<endl;

return 0;}
