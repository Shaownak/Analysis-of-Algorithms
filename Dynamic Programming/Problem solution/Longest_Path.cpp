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


void dfs(int node, vi adj[], int dp[], bool visited[]){
    visited[node] = true;

    for(int i=0; i<adj[node].size(); i++){
        if(!visited[adj[node][i]]){
            dfs(adj[node][i], adj, dp, visited);
        }
        dp[node] = max(dp[node], 1+dp[adj[node][i]]);
    }
}

void addEdge(vi adj[], int u, int v){
    adj[u].push_back(v);
}

int findlongest(vi adj[], int n){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    bool visited[n+1];
    memset(visited, false, sizeof(visited));

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, adj, dp, visited);
        }
    }
    int res = 0;
    for(int i=1; i<=n; i++){                
        res = max(res, dp[i]);
    }

    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //TODO: Start your code here:

    int m, n; 
    cin>>n;  
    vi adj[n+1];  
    for(int i=1; i<=n; i++){
        int x,y; 
        cin>>x>>y;
        addEdge(adj, x, y);
    }
    
    cout<<findlongest(adj, n);

    

    return 0;
}
