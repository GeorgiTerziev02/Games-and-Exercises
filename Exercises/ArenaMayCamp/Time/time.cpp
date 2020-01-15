#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dayWeather;
    vector<int> days;

    while(true)
    {
        cin>>dayWeather;

        if(dayWeather == 0)
        {
            break;
        }

        days.push_back(dayWeather);
    }

    int maxCount = 0;

    for(int i=0; i<days.size();i++)
    {
        int counter = 1;
        int j = i+1;

        while(j<days.size())
        {
            if(days[i]!=days[j])
            {
                break;
            }
            j++;
            counter++;
        }

        if(counter>maxCount)
            maxCount = counter;

    }

    cout<<maxCount<<endl;

return 0;}
