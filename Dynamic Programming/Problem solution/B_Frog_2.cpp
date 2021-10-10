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

const lli mod = 1e9+7;
int x[110000];
int dp[110000];

void solution(){
    int n,k; cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }

    for(int i=0; i<=n; i++){
        dp[i] = mod;
    }
    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=i+k; j++){
            if(j<n){
                dp[j] = min(dp[j], dp[i]+abs(x[i]-x[j]));
            }
        }
    }
    cout<<dp[n-1]<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //TODO: Start your code here:

    solution();




    return 0;
}
