#include<iostream>
#include<vector>
using namespace std;

bool validTree(int n, vector<vector<int>>& edges) {
    
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> edges;

    for(int i=0;i<n;i++)
    {
        int ai, bi;
        cin>>ai>>bi;

        edges.push_back({ai, bi});
    }

    if(validTree(n, edges))
        cout<<"Valid Tree"<<endl;
    else
        cout<<"Not a Valid Tree"<<endl;
}