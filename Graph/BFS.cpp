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
vector<int>adj[nmax];
bool visited[nmax];


void bfs(int u){
    visited[u] = true;
    
    queue<int>q;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int w: adj[v]){
            if(visited[w]){
                continue;
            }
            cout<<"going to "<<w<<" from "<<v<<endl;

            visited[w] = true;
            q.push(w);
        }
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

        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    for(int i=1; i<=nodes; i++){
        if(visited[i]){
            continue;
        }
        bfs(i);
    }




    return 0;
}
