#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long N;
    long R;
    unsigned long counter = 0;

    cin>>N>>R;

    vector<long> nums;

    //TEST
    /*for(int i=1; i<= 600004; i+=2)
    {
        nums.push_back(i);
    }*/

    for(int i=0;i<N;i++)
    {
       long num;
       cin>>num;

       nums.push_back(num);
    }

 	vector<long> :: iterator up;

    for(int i=0;i<nums.size();i++)
    {
        up=upper_bound(nums.begin(), nums.end(), nums[i] + R);
        counter += nums.end() - up;
        /*int j = nums.size() - 1;

        while(j>i && nums[j] - nums[i] > R)
        {
            if(nums[j] - nums[i] > R)
            {
                counter++;
            }
            else{
                break;
            }
            counter++;
            j--;
        }*/
    }

    cout<<counter;
    cout<<endl;

    return 0;
}
