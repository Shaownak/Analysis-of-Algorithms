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

int dp[1100000][3];
int a[1100000];
int b[11000000];
int c[1100000];

void solve(){
    int n; cin>>n;;
    FOR(i,0,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            if(i==0){
                if(j==0) dp[i][j] = a[i]; 
                if(j==1) dp[i][j] = b[i];
                if(j==2) dp[i][j] = c[i];
            }
            else{
                for(int k=0; k<3; k++){
                    if(j==k) continue;
                    if(j==0) dp[i][j] = max(dp[i][j], dp[i-1][k]+a[i]);
                    else if(j==1) dp[i][j] = max(dp[i][j], dp[i-1][k]+b[i]);
                    else if(j==2) dp[i][j] = max(dp[i][j], dp[i-1][k]+c[i]);
                }
            }
        }
    }
    int res = 0;
    res = max(res, dp[n-1][0]);
    res = max(res, dp[n-1][1]);
    res = max(res, dp[n-1][2]);
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
