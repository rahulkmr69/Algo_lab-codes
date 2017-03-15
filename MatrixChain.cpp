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
    rep(i,n)
    {
        ll st=i;
        rep(j,n-i-1)
        {
            ll en=st+1+j;
            path[st][en]=st;
            rep(k,en-st)
            {
                ll mid=k+st;
                ll z=dp[st][mid]+dp[mid+1][en]+mat[st].fi*mat[mid].se*mat[en].se;
                if(z<dp[st][en])
                {
                    dp[st][en]=z;
                    path[st][en]=mid;
                }
            }
        }
    }
    return dp[0][n-1];
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
    cout<<ans;
    return 0;
}
