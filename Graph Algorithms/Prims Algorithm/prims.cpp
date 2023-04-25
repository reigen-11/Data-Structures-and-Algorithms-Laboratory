#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<string> vertices = {"A","B","C","D","E"};
    vector<string> edges = {"AB","BC","CD","DE","AE","BD","AD","CE"};
    vector<int> weights = {1,2,5,4,3,6,10,2};

    vector<string> visited;
    vector<string> not_visited = vertices;

    string current_vertex = vertices[0];
    visited.push_back(current_vertex);
    not_visited.erase(current_vertex);

    for (string x: visited)
    {
        cout<<x<<endl;
    }

}
