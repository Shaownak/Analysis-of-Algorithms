#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define ss set<string>
#define mii map<int,int>
#define msi map<string,int>

const int nmax = 1e5+10;
vector<int>adj[nmax]; //adj[1] = List of 1
// adj[2] = List of 2

bool visited[nmax];

void dfs(int u){
    visited[u] = true;

    for(int v: adj[u]){
        if(visited[v]){
            continue;
        }

        cout<<" going to "<<v<<" from "<<u<<endl;

        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //TODO: Start your code here:

    int nodes, edges;
    cin>>nodes>>edges;

    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;

        // For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

        // For directed graph
        //adj[u].push_back(v);
    }

    // for(int u=1; u<=nodes; u++){
    //     cout<<u<<" - ";
    //     for(auto v: adj[u]){
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1; i<=nodes; i++){
        if(visited[i]) continue;
        dfs(i);
    }



    return 0;
}
