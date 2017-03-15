#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ll solve(vii &dp,vector< pii > &mat,vii &path,ll n)
{
    rep(i,n) dp[i][i]=0;
    for(ll i=2;i<n+1;i++)
    {
        for(ll j=0;j<n-i+1;j++)
        {
            path[j][j+i-1]=j;
            for(ll k=j;k<j+i-1;k++)
            {
                ll z=dp[j][k]+dp[k+1][j+i-1]+mat[j].fi*mat[k].se*mat[j+i-1].se;
                if(z<dp[j][j+i-1])
                {
                    dp[j][j+i-1]=z;
                    path[j][j+i-1]=k;
                }
            }
        }
    }
    return dp[0][n-1];
}
void findPath(vii &path,vi &op,vi &cl,ll st,ll en)
{
    if(en<=st) return;
    else
    {
        op[st]+=1;
        cl[en]+=1;
        op[path[st][en]+1]+=1;
        cl[path[st][en]]+=1;
        findPath(path,op,cl,st,path[st][en]);
        findPath(path,op,cl,path[st][en]+1,en);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin>>N;
    vector< pii > mat(N);
    rep(i,N) cin>>mat[i].fi>>mat[i].se;
    vii dp(N,vi(N,1e15));
    vii path(N,vi(N,-1));
    ll ans=solve(dp,mat,path,N);
    cout<<ans<<endl;
    vi op(N+2,0),cl(N+2,0);
    findPath(path,op,cl,0,N-1);
    rep(i,N)
    {
        rep(j,op[i]) cout<<"(";
        cout<<i;
        rep(j,cl[i]) cout<<")";
    }
    return 0;
}
