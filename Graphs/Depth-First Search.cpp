#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
bool visited[7] {false};
void DFS(int node)
{
    if(visited[node] == false)
    {
        visited[node] = true;

        for(int i=0; i<graph[node].size();i++)
        {
            DFS(graph[node][i]);
        }

        cout<<node<<" ";
    }
}
int main()
{

    for(int i=0; i<7; i++)
    {
        visited[i]=false;
    }

    vector<int> v0;
    //doesnt work ??? vector<int> v0{3,6};
    v0.push_back(3);
    v0.push_back(6);

    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(4);
    v2.push_back(5);

    vector<int> v3;
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(5);

    vector<int> v4;
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(6);

    vector<int> v5;
    v5.push_back(1);
    v5.push_back(2);
    v5.push_back(3);

    vector<int> v6;
    v6.push_back(0);
    v6.push_back(1);
    v6.push_back(4);

    graph.push_back(v0);
    graph.push_back(v1);
    graph.push_back(v2);
    graph.push_back(v3);
    graph.push_back(v4);
    graph.push_back(v5);
    graph.push_back(v6);

    for(int i=0;i<graph.size();i++)
    {
        DFS(i);
    }


return 0;}
