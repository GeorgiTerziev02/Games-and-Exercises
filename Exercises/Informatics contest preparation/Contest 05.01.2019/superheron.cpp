#include<bits/stdc++.h>
using namespace std;
int main()
{
    int perimeter;
    cin>>perimeter;

    int counter = 0;

    if(perimeter%4!=0)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int a=2; a <= perimeter/3; a+=2)
    {
        for(int b = a; b <= perimeter - a - 2;b+=2)
        {
           int c = perimeter - a - b;

        if (c<b) break;
        if (a+b<=c) continue;

                //if(a+b<=c || b+c<=a || c+a<=b)
                //{
                //    continue;
                //}
                if(perimeter == a+b+c)
                {

                    int smallP = perimeter/2;
                    double s = sqrt((smallP - a)*(smallP - b)*(smallP - c)*smallP);

                    if(s ==(int)s)
                    {
                        double innerRadius = s/smallP;
                        double outerRadius = (a*b*c)/(4*s);

                        if(innerRadius == (int)innerRadius && outerRadius == (int) outerRadius)
                        {
                            counter++;
                        }

                    }
                    else
                    {
                        continue;
                    }
                }
        }
    }
    cout<<counter<<endl;


return 0;}
