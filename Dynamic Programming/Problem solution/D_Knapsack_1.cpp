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

int w[110000];
int v[110000];
lli dp[110000];


void solve(){
    int a,b;
    cin>>a>>b;
    FOR(i,0,a){
        cin>>w[i]>>v[i];
    }

    for(int i=0; i<a; i++){
        for(int j=b; j>=0; j--){
            if(j+w[i]<=b) dp[j+w[i]] = max(dp[j+w[i]], dp[j]+v[i]);
        }
    }

    lli res=0;

    for(int i=0; i<=b; i++){
        res = max(dp[i], res);
    }

    cout<<res<<endl;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //TODO: Start your code here:

    
    solve();



    return 0;
}
