#include<bits/stdc++.h>
using namespace std;

bool contains(vector<int> v, int k)
{
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i]==k)
        {
            return true;
        }
    }

    return false;
}
int findDistance(vector<vector<int> > graphs, int currentPosition, int searchedNumber, int currentDistance)
{
    if(contains(graphs[currentPosition - 1], searchedNumber))
    {
        return currentDistance;
    }
    else{
        return currentDistance + 1;
    }
    /*for(int i = 0; i<graphs[currentPosition - 1].size(); i++)
    {
        findDistance(graphs, graphs[currentPosition - 1][i], searchedNumber, currentDistance+1);
    }*/
}

int main()
{
    vector<vector<int> > graphs;

    int nodes;
    int ribs;

    int cNode;
    int distance;

    cin>>nodes>>ribs>>cNode>>distance;

    for(int i = 0; i<nodes;i++)
    {
        vector<int> v1;
        graphs.push_back(v1);
    }

    for(int i=0;i<ribs;i++)
    {
        int currentNode;
        int currentRib;
        cin>>currentNode>>currentRib;

        graphs[currentNode - 1].push_back(currentRib);
        graphs[currentRib - 1].push_back(currentNode);
    }

    /*for(int i = 0; i<ribs; i++)
    {
        int currentNode;
        int currentRib;
        cin>>currentNode>>currentRib;

        if(currentNode - 1 >= graphs.size())
        {
            if(currentRib - 1 >= graphs.size() )
            {
                vector<int> v1;
                vector<int> v2;

                v1.push_back(currentRib);
                v2.push_back(currentNode);
                graphs.push_back(v1);
                graphs.push_back(v2);
            }
            else
            {
                graphs[currentNode - 1].push_back(currentRib);

                vector<int> v2;
                v2.push_back(currentNode);

                graphs.push_back(v2);
            }
        }
        else{

        if(currentRib - 1 >= graphs.size() )
            {
                graphs[currentNode - 1].push_back(currentRib);
                vector<int> v2;
                v2.push_back(currentNode);

                graphs.push_back(v2);
            }

        else{
        graphs[currentNode - 1].push_back(currentRib);
        graphs[currentRib - 1].push_back(currentNode);
        }}

    }*/
    vector<int> kPeriphery;

    for(int i=0;i<graphs.size();i++)
    {
        //cout<<i + 1<<"  "<<" "<<findDistance(graphs, i + 1, cNode, 1)<<endl;
        if(i+1!=cNode && findDistance(graphs, i + 1, cNode, 1) > distance)
        {
            kPeriphery.push_back(i+1);
        }
    }

    /*for(int i = 0 ; i < graphs.size(); i++)
    {
        cout<<i+1<<"links with:   ";
        for(int j=0;j<graphs[i].size();j++)
        {

            cout<<graphs[i][j]<<" ";
        }

        cout<<endl;
    }*/

    cout<<kPeriphery.size()<<endl;

    if(kPeriphery.size()!=0)
    {
    for(int i = 0; i<kPeriphery.size();i++)
    {
      cout<<kPeriphery[i]<<endl;
    };
    }

 return 0;
}
