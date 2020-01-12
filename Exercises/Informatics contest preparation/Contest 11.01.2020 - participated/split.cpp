#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    //TEST
    /*for(int i = 0; i<1000000;i++)
    {
        if(i%2 == 0)
        {
            input+='0';
        }
        else
        {
            input += '1';
        }
    }*/

    int counter = 0;

    for(int i=0;i<input.length();i++)
    {
        int currentCounter = 1;
        int j = i+1;

        while(input[i] == input[j])
        {
            currentCounter++;

            j++;
        }

        counter++;

        //cout<<currentCounter;
        i += 2 * currentCounter - 1;
    }

    cout<<counter;
    cout<<endl;

    return 0;
}
